/*
 * thermistor.c
 *
 *  Created on: Apr 27, 2022
 *      Author: RAJ
 *
 *	Module to read a thermistor and return the temperature.
 */
#include "thermistor.h"
#include <string.h>
#include "main.h"
#include "hal_adc.h"

// private variables
enum unitsEnum {
	celsius,
	fahrenheit,
	kelvin
};
static enum unitsEnum units;

// private function declarations
static float_t thermistor_get_reading_c(uint16_t adc_count);
static float_t thermistor_get_reading_f(uint16_t adc_count);
static float_t thermistor_get_reading_k(uint16_t adc_count);

void thermistor_init(void) {
	hal_adc_init();
}

float_t thermistor_get_reading(void) {
	uint16_t adc_count = hal_adc_read_thermistor();

	float_t result;
	switch(units) {
	case fahrenheit:
		result = thermistor_get_reading_f(adc_count);
		break;
	case kelvin:
		result = thermistor_get_reading_k(adc_count);
		break;
	case celsius:
	default:
		result = thermistor_get_reading_c(adc_count);
		break;
	}

	// round the result to the nearest tenth.
	result *= 10;
	result += 0.5;
	result = floor(result);
	result /= 10;

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

static float_t thermistor_get_reading_c(uint16_t adc_count) {
	return thermistor_get_reading_k(adc_count) - 273.15;
}

static float_t thermistor_get_reading_f(uint16_t adc_count) {
	return (thermistor_get_reading_c(adc_count) * 9 / 5) + 32;
}

static float_t thermistor_get_reading_k(uint16_t adc_count) {
	// convert AD reading to a voltage
	// V = (Vref / 2^N) * c
	// where:
	//		V is the voltage at the ADC
	//		Vref is the ADC reference voltage
	//		N is the ADC resolution
	//		c is the ADC readings
	const float_t Vref = 3.3;
	const uint8_t N = 12;
	const float_t max_adc_count = (1 << N) - 1;
	const float_t volts_per_adc_count = Vref / max_adc_count;

	float_t voltage_reading = volts_per_adc_count * adc_count;

	// find resistance from the voltage
	// Rthemistor = (R * Vt) / (Vs - Vt)
	// where:
	//		R is the resistance of the upper resistor in the voltage divider
	// 		Vs is the voltage applied to the top of the voltage divider
	//		Vt is the voltage at the node between the thermistor and resistor.
	const float_t R = 10000;
	const float_t Vs = Vref;
	float_t Rthemistor = (R * voltage_reading) / (Vs - voltage_reading);

	// find temperature from the resistance using the Steinhart Hart equation
	// 1 / T = ((1 / T0) + ln(Rt / R0) / B)
	// where:
	//		T is the current temperature
	//		Rt is the current resistance of the thermistor
	//		R0 is the resistance at the base temperature
	//		B is the thermistor's beta value
	const float_t T0 = 25 + 273.15;
	const float_t R0 = 10000;
	const float_t beta = 3965;
	float_t temperature = 1 / (((1 / T0) + log(Rthemistor / R0) / beta));

	return temperature;
}
