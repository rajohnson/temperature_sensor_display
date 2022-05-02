/*
 * hal_spi.h
 *
 *  Created on: May 01, 2022
 *      Author: RAJ
 *  HAL abstraction layer to provide SPI.
 */

#ifndef HAL_SPI_H_
#define HAL_SPI_H_

#include <stdint.h>

/*
 * Initialize the spi peripheral.
 */
void hal_spi_init(void);

/*
 * Set output pin state to the value specified by the state parameter.
 */
uint8_t hal_spi_read(uint8_t num_bytes);


#endif /* HAL_SPI_H_ */
