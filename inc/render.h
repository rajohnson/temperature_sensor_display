/*
 * render.h
 *
 *  Created on: Apr 27, 2022
 *      Author: RAJ
 *
 *	Rendering system. Takes in values from the model and processes them into
 *	 as form that can be used within the view.
 */

#ifndef INC_RENDER_H_
#define INC_RENDER_H_

#include <math.h>

/*
 * Initializes the rendering module and underlying mechanism
 */
void render_init(void);

/*
 * Renders the readings to the screen.
 */
void render_values(float_t thermistor_reading, char* thermistor_units, float_t thermocouple_reading, char* thermocouple_units);


#endif /* INC_RENDER_H_ */
