/*
 * hal_delay.c
 *
 *  Created on: Apr 30, 2022
 *      Author: RAJ
 */

#include "hal_delay.h"
#include "main.h"

void hal_delay_init(void) {
	// init is already happening in main here started by cube. Just letting it happen in this case.
	LL_TIM_EnableCounter(TIM17);
}

void hal_delay_us(uint32_t delay_us) {
	uint32_t starting_count = LL_TIM_GetCounter(TIM17);
	while(LL_TIM_GetCounter(TIM17) - starting_count  <= delay_us + 1) {  // extra us for partially consumed period when starting.
		// wait
	}
}
void hal_delay_ms(uint32_t delay_ms) {
	HAL_Delay(delay_ms);
}
