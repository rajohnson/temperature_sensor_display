/*
 * hal_adc.h
 *
 *  Created on: Apr 30, 2022
 *      Author: RAJ
 *	HAL abstraction layer for ADC readings.
 */

#ifndef HAL_ADC_H_
#define HAL_ADC_H_

#include <stdint.h>

/*
 * Initialize the adc.
 */
void hal_adc_init(void);

/*
 * Take adc reading on the channel connected to the thermistor and return the result.
 *
 * Blocking.
 */
uint16_t hal_adc_read_thermistor(void);

#endif /* HAL_ADC_H_ */
