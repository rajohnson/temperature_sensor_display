/*
 * thermistor.h
 *
 *  Created on: Apr 27, 2022
 *      Author: RAJ
 *
 *	Module to read a thermistor and return the temperature.
 */

#ifndef THERMISTOR_H_
#define THERMISTOR_H_

#include <math.h>
#include <stdbool.h>

#define UNITS_KELVIN 		("K")
#define UNITS_FAHRENHEIT 	("F")
#define UNITS_CELSIUS 		("C")

/*
 * Initialize the thermistor module.
 */
void thermistor_init(void);

/*
 * Return the thermistor temperature reading in the units specifed with 1
 *  decimal place of accuracy.
 *
 * If the module is in an error state the functions will return NaN.
*/
float_t thermistor_get_reading(void);

/*
 * Get a string specifying the current units to represent readings.
 */
char* thermistor_get_units(void);

/*
 * Set the current units to represent readings. Valid inputs are
 *  ['K', 'F', 'C'] for kelvin, fahrenheit, and celsius respectively.
 *  If a different value is given then no change shall be made.
 */
void thermistor_set_units(char* newUnits);

#endif /* THERMISTOR_H_ */
