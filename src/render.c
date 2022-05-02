/*
 * render.c
 *
 *  Created on: Apr 27, 2022
 *      Author: RAJ
 *
 *	Rendering system. Takes in values from the model and processes them into
 *	 as form that can be used within the view.
 */

#include "render.h"
#include "display.h"
#include <stdio.h>
#include <string.h>

// todo - Currently using floating point support in printf - massive resource
//  hog. Could relatively easily switch to fixed precision.

// private variables
struct renderingBufferStruct {
	char line[MAX_ROW][MAX_COLUMN];
};

static struct renderingBufferStruct renderingData;

enum lineEnum{
	thermistor = 0,
	thermocouple = 1,
	end = MAX_ROW
};

// private function declarations
static void update_display(void);
static void clear_line_data(enum lineEnum line);

// function definitions
void render_init(void) {
	display_init();

	for(uint8_t i = 0; i < MAX_ROW; ++i) {
		clear_line_data(i);
	}

	update_display();
}

void render_values(float_t thermistor_reading, char* thermistor_units, float_t thermocouple_reading, char* thermocouple_units) {
	clear_line_data(thermistor);
	if(thermistor_reading == NAN) {
		snprintf(renderingData.line[thermistor], MAX_COLUMN, "Thermistor: error");
	} else {
		snprintf(renderingData.line[thermistor], MAX_COLUMN, "Thermistor: %.1f%s", thermistor_reading, thermistor_units);
	}

	clear_line_data(thermocouple);
	if(thermocouple_reading == NAN) {
		snprintf(renderingData.line[thermocouple], MAX_COLUMN, "Thermocouple: error");
	} else {
		snprintf(renderingData.line[thermocouple], MAX_COLUMN, "Thermocouple: %.0f%s", thermocouple_reading, thermocouple_units);
	}

	update_display();
}

/*
 * Updates the display from the rendering buffers.
 */
static void update_display(void) {
	display_clear_all();

	for(uint8_t i = 0; i < MAX_ROW; ++i) {
		display_write_row(i, renderingData.line[i]);
	}
}

/*
 * Clears a line of the rendering buffers.
 */
static void clear_line_data(enum lineEnum lineToClear) {
	memset(renderingData.line[lineToClear], 0, MAX_COLUMN);
}
