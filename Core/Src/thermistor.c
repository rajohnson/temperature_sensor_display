/*
 * thermistor.c
 *
 *  Created on: Apr 27, 2022
 *      Author: RAJ
 */
#include "thermistor.h"
#include <string.h>

// private variables
enum unitsEnum {
	celsius,
	fahrenheit,
	kelvin
};
static enum unitsEnum units;

// private function declarations
static float_t thermistor_get_reading_c(void);
static float_t thermistor_get_reading_f(void);
static float_t thermistor_get_reading_k(void);

void thermistor_init(void) {
	// todo - init adc
}

void thermistor_begin_reading(void) {
	// todo -
}

bool thermistor_reading_complete(void) {
	return true;	// todo
}

float_t thermistor_get_reading(void) {
	float_t result;
	switch(units) {
	case fahrenheit:
		result = thermistor_get_reading_f();
		break;
	case kelvin:
		result = thermistor_get_reading_k();
		break;
	case celsius:
		result = thermistor_get_reading_c();
		break;
	default:
		result = thermistor_get_reading_c();
		break;
	}
	return result;
}

char* thermistor_get_units(void) {
	char* result;
	switch(units) {
	case fahrenheit:
		result = UNITS_FAHRENHEIT;
		break;
	case kelvin:
		result = UNITS_KELVIN;
		break;
	case celsius:
		result = UNITS_CELSIUS;
		break;
	default:
		result = UNITS_CELSIUS;
		break;
	}
	return result;
}

void thermistor_set_units(char* newUnits) {
	if(strlen(newUnits) != 1) {
		return;
	}
	if(strcmp(newUnits, UNITS_CELSIUS) == 0) {
		units = celsius;
	} else if(strcmp(newUnits, UNITS_KELVIN) == 0) {
		units = kelvin;
	} else if(strcmp(newUnits, UNITS_FAHRENHEIT) == 0) {
		units = fahrenheit;
	}
}

static float_t thermistor_get_reading_c(void) {
	return 100;	// todo
}

static float_t thermistor_get_reading_f(void) {
	return (thermistor_get_reading_c() * 9 / 5) + 32;	// todo round
}

static float_t thermistor_get_reading_k(void) {
	return thermistor_get_reading_c() + 273.15;	// todo round
}
