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
	return thermistor_get_reading_k() - 273.15;	// todo
}

static float_t thermistor_get_reading_f(void) {
	return (thermistor_get_reading_c() * 9 / 5) + 32;	// todo round
}

static float_t thermistor_get_reading_k(void) {
	// convert AD reading to a voltage
	// V = (Vref / 2^N) * c
	// where:
	//		V is the voltage at the ADC
	//		Vref is the ADC reference voltage
	//		N is the ADC resolution
	//		c is the ADC readings

	// find resistance from the voltage
	// Rthemistor = (R * Vs) / (1 - Vs)
	// where:
	//		R is the resistance of the upper resistor in the voltage divider
	// 		Vs is the voltage applied to the top of the voltage divider

	// find temperature from the resistance using the Steinhart Hart equation
	// 1 / T = ((1 / T0) + ln(Rt / R0) / B)
	// where:
	//		T is the current temperature
	//		Rt is the current resistance of the thermistor
	//		R0 is the resistance at the base temperature
	//		B is the thermistor's beta value

	return 273.15;	// todo round
}
