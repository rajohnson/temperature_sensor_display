/*
 * thermistor.c
 *
 *  Created on: Apr 27, 2022
 *      Author: RAJ
 */
#include "thermistor.h"

void thermistor_init(void) {
	// todo
}

void thermistor_begin_reading(void) {
	// todo
}

bool thermistor_reading_complete(void) {
	return true;	// todo
}

float_t thermistor_get_reading_c(void) {
	return 100;	// todo
}

float_t thermistor_get_reading_f(void) {
	return (thermistor_get_reading_c() * 9 / 5) + 32;	// todo round
}

float_t thermistor_get_reading_k(void) {
	return thermistor_get_reading_c() + 273.15;	// todo round
}
