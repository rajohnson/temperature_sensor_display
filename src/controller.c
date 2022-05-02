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
#include "thermocouple.h"
#include "render.h"

void controller_init(void) {
    thermistor_init();
    thermocouple_init(17.5);
    render_init();
}

void controller_execute_cycle(void) {
  	  render_values(thermistor_get_reading(), thermistor_get_units(), thermocouple_get_reading(), thermocouple_get_units());
}
