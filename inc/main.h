/*
 * main.h
 *
 *  Created on: 31.8.2017
 *      Author: jore
 */

#ifndef INC_MAIN_H_
#define INC_MAIN_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#define WRITE_REG		0x0231


void open_SPI();

#ifdef __cplusplus
}
#endif

#endif /* INC_MAIN_H_ */
