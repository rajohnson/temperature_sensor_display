/*
 * thermocouple.c
 *
 *  Created on: May 01, 2022
 *      Author: RAJ
 *
 *	Module to read a thermocouple attached to a Maxim MAX6675 and return the
 *	 temperature that was read.
 */
#include "thermocouple.h"
#include <string.h>
#include <stdint.h>
#include "main.h"
#include "hal_spi.h"
#include "iso646.h"
#include "hal_gpio.h"

// private variables
enum unitsEnum {
	celsius,
	fahrenheit,
	kelvin
};
static enum unitsEnum units;
static float_t offset = 0; // calibration offset (in degrees C) applied to all readings

// private function declarations
static uint16_t thermocouple_get_reading_c(uint16_t reading);
static uint16_t thermocouple_get_reading_f(uint16_t reading);
static uint16_t thermocouple_get_reading_k(uint16_t reading);

void thermocouple_init(float_t calibration_offset) {
	hal_spi_init();
	offset = calibration_offset;
}

float_t thermocouple_get_reading(void) {
	hal_gpio_set_thermocouple_cs(low);
	uint16_t reading = hal_spi_read(1);
	hal_gpio_set_thermocouple_cs(high);

	if((reading bitand 0x04) >> 2) {	// thermocouple not connected.
		return NAN;
	}

	float_t result;
	switch(units) {
	case fahrenheit:
		result = thermocouple_get_reading_f(reading);
		break;
	case kelvin:
		result = thermocouple_get_reading_k(reading);
		break;
	case celsius:
	default:
		result = thermocouple_get_reading_c(reading);
		break;
	}

	// round the result to the nearest tenth.
	result *= 10;
	result += 0.5;
	result = floor(result);
	result /= 10;

	return result;
}

char* thermocouple_get_units(void) {
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

void thermocouple_set_units(char* newUnits) {
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

static uint16_t thermocouple_get_reading_c(uint16_t reading) {
	return ((reading bitand 0xfff8) >> 3) + offset;
}

static uint16_t thermocouple_get_reading_f(uint16_t reading) {
	return (thermocouple_get_reading_c(reading) * 9 / 5) + 32;
}

static uint16_t thermocouple_get_reading_k(uint16_t reading) {
	return thermocouple_get_reading_c(reading) + 273.15;
}
