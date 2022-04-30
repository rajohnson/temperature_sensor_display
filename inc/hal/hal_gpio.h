/*
 * hal_gpio.h
 *
 *  Created on: Apr 30, 2022
 *      Author: RAJ
 */

#ifndef HAL_GPIO_H_
#define HAL_GPIO_H_

#include <stdint.h>

enum halIOStateEnum {
  high=1,
  low=0
};

/*
 * Initialize the io pins, set direction.
 */
void hal_gpio_init(void);

/*
 * Set output pin state to the value specified by the state parameter.
 */
void hal_gpio_set_display_rs(enum halIOStateEnum state);
void hal_gpio_set_display_en(enum halIOStateEnum state);
void hal_gpio_set_display_d7(enum halIOStateEnum state);
void hal_gpio_set_display_d6(enum halIOStateEnum state);
void hal_gpio_set_display_d5(enum halIOStateEnum state);
void hal_gpio_set_display_d4(enum halIOStateEnum state);


#endif /* HAL_GPIO_H_ */
