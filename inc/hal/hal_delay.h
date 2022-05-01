/*
 * hal_delay.h
 *
 *  Created on: Apr 30, 2022
 *      Author: RAJ
 *	HAL abstraction layer to provide delays.
 */

#ifndef HAL_DELAY_H_
#define HAL_DELAY_H_

#include <stdint.h>

/*
 * Initialize the delay module.
 */
void hal_delay_init(void);

/*
 * Blocking delay for given number of us.
 */
void hal_delay_us(uint32_t delay_us);

/*
 * Blocking delay for given number of ms.
 */
void hal_delay_ms(uint32_t delay_ms);

/*
 * Callback for us timer.
 */
void hal_delay_us_timer_isr_callback(void);

#endif /* HAL_DELAY_H_ */
