/*
 * display.c
 *
 *  Created on: Apr 27, 2022
 *      Author: RAJ
 *
 *  Driver for HD44780U character LCD display with 20x4 character glass.
 *  Uses the 4-bit data mode (each command is split into 2 4-bit nibbles).
 *
 *  Expect the hal_gpio library to provide functions to drive pins and to define
 *   which is used. The hal_delay is also required for timing.
 *
 *  Datasheet available here: https://www.sparkfun.com/datasheets/LCD/HD44780.pdf
 */

#include "display.h"
#include <string.h>
#include "hal_gpio.h"
#include "hal_delay.h"
#include <iso646.h>


// private definitions and variables
enum rsEnum {
	instruction=0,
	data=1
};

enum tc2004aCommandEnum {
	initialization1=0x03,	// overloaded with full command
	initialization2=0x03,	// overloaded with full command
	initialization3=0x03,	// overloaded with full command
	interface_4bit=0x02,	// overloaded with full command
	lines_and_font=0x28,	// overloaded with full command - 5*8 char font set and multiple lines
	clear_display=0x01,
	return_home=0x02,
	set_entry_mode=0x04,
	display_settings=0x08,
	cursor_display_shift=0x10,
	function_settings=0x20,
	set_cgram_address=0x40,
	set_ddram_address=0x80,
	write_data=0x00
};

enum displaySettingsEnum {
	cursor = 0x02,		// not currently implemented - always off
	display = 0x04,
	blink = 0x01		// not currently implemented - always off
};

enum entryModeEnum {
	increment = 0x02,
	shift = 0x01
};

static uint8_t displaySettings = not cursor | not blink | not display;	// all off
static uint8_t entryMode = increment | not shift;

static uint8_t row_start_address[MAX_ROW] = { 0x00, 0x40, 0x00 + MAX_COLUMN, 0x40 + MAX_COLUMN };

// private function declarations
static void writeNibble(uint8_t nibble, enum rsEnum register_select);
static void writeByte(uint8_t data, enum rsEnum register_select);

void display_init(void) {
	hal_delay_init();

	// The display needs at least 40ms (if Vsupply is 3.3V, need >15ms if 3.3V)
	//  to start up before beginning the initialization sequence.
	hal_delay_ms(40);

	writeNibble(initialization1, instruction);
	hal_delay_ms(5);	// >4.1ms delay

	writeNibble(initialization2, instruction);
	hal_delay_us(100);

	writeNibble(initialization3, instruction);
	hal_delay_us(53);

	writeNibble(interface_4bit, instruction);
	hal_delay_us(53);

	writeByte(lines_and_font, instruction);

	display_enable();

	writeByte(set_entry_mode | entryMode, instruction);

	display_clear_all();

	hal_delay_us(53); // todo - rm line
}

void display_clear_all(void) {
	writeByte(clear_display, instruction);
	hal_delay_ms(2);		// 1.52ms execution time
}

void display_clear_row(uint8_t row) {
	char blank_data[MAX_COLUMN];
	memset(blank_data, ' ', MAX_COLUMN);

	display_set_cursor(row, 0);
	display_write(blank_data);
}

void display_set_cursor(uint8_t row, uint8_t column) {
	if(row >= MAX_ROW or column >= MAX_COLUMN) {
		return;
	}
	writeByte(set_ddram_address | (row_start_address[row] + column), instruction);

	hal_delay_us(37);	// command execution time
}

void display_write(char* text) {
	for(uint8_t col = 0; col < MAX_COLUMN and text[col] != 0; ++ col) {
		writeByte(text[col], data);

		hal_delay_us(37);	// command execution time
	}
}

void display_write_row(uint8_t row, char* text) {
	display_clear_row(row);
	display_set_cursor(row, 0);
	display_write(text);
}

void display_enable(void) {
	displaySettings |= display;
	writeByte(display_settings | displaySettings, instruction);

	hal_delay_us(37);	// command execution time
}

void display_disable(void) {
	displaySettings &= ~display;
	writeByte(display_settings | displaySettings, instruction);

	hal_delay_us(37);	// command execution time
}

/*
 * Writes a nibble to the display parallel interface.
 * 	Sets rs bit, raises en, writes data, and drops en.
 *
 * nibble: data to be written upper 4 bytes are ignored
 * 			[x, x, x, x, D7, D6, D5, D4]
 *
 * register_select: selects which register the data is written to
 * 			(instruction/data). Encoded based on the rsEnum enum.
 */
static void writeNibble(uint8_t nibble, enum rsEnum register_select) {
	hal_gpio_set_display_rs(register_select);	// rs has 30 ns setup time before en rising edge
	hal_gpio_set_display_en(high);

	hal_gpio_set_display_d7((nibble bitand 0x08) >> 3);
	hal_gpio_set_display_d6((nibble bitand 0x04) >> 2);
	hal_gpio_set_display_d5((nibble bitand 0x02) >> 1);
	hal_gpio_set_display_d4(nibble bitand 0x01);  // data have 40 ns setup time before en falling edge

	hal_delay_us(1);

	hal_gpio_set_display_en(low);		// data and rs have 10 ns hold time after this
}

/*
 * Writes a byte to the display parallel interface.
 *  Breaks the transaction into two 4 bit transfers.
 *  The upper nibble (D7-D4) is sent first and the lower nibble (D3-D0) second.
 *
 *  data: byte of data to be written to the display.
 * 			[D7, D6, D5, D4, D3, D2, D1, D0]
 *
 * register_select: selects which register the data is written to
 * 			(instruction/data). Encoded based on the rsEnum enum.
 */
static void writeByte(uint8_t data, enum rsEnum register_select) {
	writeNibble((data bitand 0xF0) >> 4, register_select);
	writeNibble(data bitand 0x0F, register_select);
}
