/*
 * hal_adc.c
 *
 *  Created on: May 1, 2022
 *      Author: RAJ
 *	HAL abstraction layer for ADC readings.
 */

#include "hal_adc.h"
#include "main.h"

void hal_adc_init(void) {
	LL_ADC_StartCalibration(ADC1);
	while(LL_ADC_IsCalibrationOnGoing(ADC1)) {

	}

	LL_ADC_Enable(ADC1);
}

uint16_t hal_adc_read_thermistor(void) {
	uint16_t adc_reading;
	 LL_ADC_REG_StartConversion(ADC1);
	 while(LL_ADC_IsActiveFlag_EOC(ADC1) == 0);
	 if( LL_ADC_IsActiveFlag_EOC(ADC1) ) LL_ADC_ClearFlag_EOC(ADC1);
	 adc_reading = LL_ADC_REG_ReadConversionData12(ADC1);
	 LL_ADC_REG_StopConversion(ADC1);

	 return adc_reading;
}
