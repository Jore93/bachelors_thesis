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
#include "wiringPiSPI.h"
#include "wiringPi.h"
#include "reg_def.h"


#define WRITE_REG		0x0231
#define READ_REG		0x5600		// Not actual


bool openSPI();
void writeSPI();
void readSPI(uint8_t *data_ptr, int range);
void sendToAzure(uint8_t *data_ptr);

#ifdef __cplusplus
}
#endif

#endif /* INC_MAIN_H_ */
