/*
 * hal_gpio.c
 *
 *  Created on: Apr 30, 2022
 *      Author: RAJ
 *  HAL abstraction layer to provide GPIO.
 */

#include "hal_gpio.h"
#include "main.h"


static void set_st_hal_output(enum halIOStateEnum state, GPIO_TypeDef* port, uint16_t pin);

void hal_gpio_init(void) {
	// todo
}

void hal_gpio_set_display_rs(enum halIOStateEnum state) {
	set_st_hal_output(state, DISPLAY_RS_GPIO_Port, DISPLAY_RS_Pin);
}

void hal_gpio_set_display_en(enum halIOStateEnum state) {
	set_st_hal_output(state, DISPLAY_EN_GPIO_Port, DISPLAY_EN_Pin);
}

void hal_gpio_set_display_d7(enum halIOStateEnum state) {
	set_st_hal_output(state, DISPLAY_D7_GPIO_Port, DISPLAY_D7_Pin);
}

void hal_gpio_set_display_d6(enum halIOStateEnum state) {
	set_st_hal_output(state, DISPLAY_D6_GPIO_Port, DISPLAY_D6_Pin);
}

void hal_gpio_set_display_d5(enum halIOStateEnum state) {
	set_st_hal_output(state, DISPLAY_D5_GPIO_Port, DISPLAY_D5_Pin);
}

void hal_gpio_set_display_d4(enum halIOStateEnum state) {
	set_st_hal_output(state, DISPLAY_D4_GPIO_Port, DISPLAY_D4_Pin);
}

static void set_st_hal_output(enum halIOStateEnum state, GPIO_TypeDef* port, uint16_t pin) {
	GPIO_PinState st_hal_state;
	if(state == low) {
		st_hal_state = GPIO_PIN_RESET;
	} else {
		st_hal_state = GPIO_PIN_SET;
	}
	HAL_GPIO_WritePin(port, pin, st_hal_state);
}
