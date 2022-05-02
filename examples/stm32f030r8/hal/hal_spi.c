/*
 * hal_spi.c
 *
 *  Created on: May 01, 2022
 *      Author: RAJ
 *  HAL abstraction layer to provide SPI.
 */

#include "hal_spi.h"
#include "main.h"
#include <iso646.h>

void hal_spi_init(void) {
	// init happens in main from cubeMX for this implementation.
}

uint8_t hal_spi_read(uint8_t num_bytes) {
//	hspi1
	uint8_t data[2] = {0};
	if(HAL_SPI_Receive(&hspi1, data, num_bytes, 100)) {
		// error
		return 0x04;
	}
	return ((data[1] << 8) bitor data[0]);
}
