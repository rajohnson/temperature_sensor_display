/*
 * thermocouple.h
 *
 *  Created on: May 01, 2022
 *      Author: RAJ
 *
 *	Module to read a thermocouple attached to a Maxim MAX6675 and return the
 *	 temperature that was read.
 */

#ifndef THERMOCOUPLE_H_
#define THERMOCOUPLE_H_

#include <math.h>

#define UNITS_KELVIN 		("K")
#define UNITS_FAHRENHEIT 	("F")
#define UNITS_CELSIUS 		("C")

/*
 * Initialize the thermocouple module.
 */
void thermocouple_init(float_t calibration_offset);

/*
 * Return the thermocouple temperature reading in the units specifed rounded to
 *  the nearest integer value.
 *
 * If the module is in an error state the functions will return NaN.
*/
float_t thermocouple_get_reading(void);

/*
 * Get a string specifying the current units to represent readings.
 */
char* thermocouple_get_units(void);

/*
 * Set the current units to represent readings. Valid inputs are
 *  ['K', 'F', 'C'] for kelvin, fahrenheit, and celsius respectively.
 *  If a different value is given then no change shall be made.
 */
void thermocouple_set_units(char* newUnits);

#endif /* THERMOCOUPLE_H_ */
