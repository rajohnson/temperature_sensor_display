/*
 * display.h
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

#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_

#include <stdint.h>

/*
 * Initialize and clear the display.
 */
void display_init(void);

/*
 * Clears the entire display
 */
void display_clear_all(void);

/*
 * Clears the specified row.
 */
void display_clear_row(uint8_t row);

/*
 * Sets the cursor position to the specified location.
 *
 * If row < MAX_ROW or column is > MAX_COLUMN then no action is taken.
 *
 * Both row and column are zero indexed.
 */
void display_set_cursor(uint8_t row, uint8_t column);

/*
 * Write text to the display. Starts at the current cursor location.
 *
 * Text: pointer to C string. If the string is longer than the line length the
 * 	displayed text is truncated.
 */
void display_write(char* text);

/*
 * Write text to the display. Starts at the beginning of the specified row.
 */
void display_write_row(uint8_t row, char* text);

/*
 * Enable showing text on the display
 */
void display_enable(void);

/*
 * Disable showing text on the display.
 */
void display_disable(void);

#define MAX_ROW	(4)
#define MAX_COLUMN	(20)

#endif /* INC_DISPLAY_H_ */
