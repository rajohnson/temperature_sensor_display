/*
 * controller.h
 *
 *  Created on: May 01, 2022
 *      Author: RAJ
 *
 *	Supervisory module to take readings from component model modules and pass
  *  data to view modules to be presented.
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <math.h>
#include <stdbool.h>

#define UNITS_KELVIN 		("K")
#define UNITS_FAHRENHEIT 	("F")
#define UNITS_CELSIUS 		("C")

/*
 * Initialize the controller module.
 */
void controller_init(void);

/*
 * Executes a single cycle of the read/update task sequence.
 *
 * A delay should be placed between calls to this.
*/
void controller_execute_cycle(void);

#endif /* CONTROLLER_H_ */
