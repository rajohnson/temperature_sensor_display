/*
 * display.c
 *
 *  Created on: Apr 27, 2022
 *      Author: RAJ
 */

#include "display.h"

void display_init(void) {
	// todo
}

void display_clear_all(void) {
	// todo
}

void display_clear_row(uint8_t row) {
	// todo
}

void display_set_cursor(uint8_t row, uint8_t column) {
	// todo
}

void display_write(char* text) {
	// todo
}

void display_write_row(uint8_t row, char* text) {
	display_clear_row(row);
	display_set_cursor(row, 0);
	display_write(text);
}
