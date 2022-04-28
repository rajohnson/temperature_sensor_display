/*
 * thermistor.h
 *
 *  Created on: Apr 27, 2022
 *      Author: RAJ
 */

#ifndef THERMISTOR_H_
#define THERMISTOR_H_

#include <math.h>
#include <stdbool.h>

/*
 * Initialize the thermistor module.
 */
void thermistor_init(void);

/*
 * Begins a thermistor reading.
 */
void thermistor_begin_reading(void);

/*
 * Checks to determine if the reading is in progress (false) or has been
 * 	completed (true).
 */
bool thermistor_reading_complete(void);

/*
 * Return the thermistor temperature reading in the specifed units of each
 * 	function with 1 decimal place of accuracy.
 *
 * If the module is in an error state the functions will return NaN.
*/
float_t thermistor_get_reading_c(void);
float_t thermistor_get_reading_f(void);
float_t thermistor_get_reading_k(void);


#endif /* THERMISTOR_H_ */
