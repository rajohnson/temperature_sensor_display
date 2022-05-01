/*
 * controller.h
 *
 *  Created on: May 01, 2022
 *      Author: RAJ
 *
 *	Supervisory module to take readings from component model modules and pass
  *  data to view modules to be presented.
 */

#include "controller.h"
#include "thermistor.h"
#include "render.h"

void controller_init(void) {
    thermistor_init();
    render_init();
}

void controller_execute_cycle(void) {
  	  render_values(thermistor_get_reading(), thermistor_get_units());
}
