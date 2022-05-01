/*
 * hal_delay.c
 *
 *  Created on: Apr 30, 2022
 *      Author: RAJ
 */

#include "hal_delay.h"
#include "main.h"

void hal_delay_us(uint32_t delay_us) {
	hal_delay_ms((delay_us / 1000) + 1);	// todo - improve resolution with better implementation
}
void hal_delay_ms(uint32_t delay_ms) {
	HAL_Delay(delay_ms);
}
