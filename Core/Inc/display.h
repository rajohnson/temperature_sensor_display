/*
 * display.h
 *
 *  Created on: Apr 27, 2022
 *      Author: RAJ
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
void display_clear_line(uint8_t row);

/*
 * Sets the cursor position to the specified location.
 */
void display_set_cursor(uint8_t row, uint8_t column);

/*
 * Write text to the display.
 */
void display_write(char* text);

#define MAX_ROWS	(4)
#define MAX_COLUMNS	(20)

#endif /* INC_DISPLAY_H_ */