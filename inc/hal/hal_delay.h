/*
 * hal_delay.h
 *
 *  Created on: Apr 30, 2022
 *      Author: RAJ
 */

#ifndef HAL_DELAY_H_
#define HAL_DELAY_H_

#include <stdint.h>

/*
 * Blocking delay for given number of us.
 */
void hal_delay_us(uint32_t delay_us);

/*
 * Blocking delay for given number of ms.
 */
void hal_delay_ms(uint32_t delay_ms);

#endif /* HAL_DELAY_H_ */
