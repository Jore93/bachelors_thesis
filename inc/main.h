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


#define BAUD			9600
#define MOSI 			19
#define MISO 			21
#define SCLK 			23
#define CE0				24

#define WRITE_REG		0x0232
#define READ_REG		0x0000		// Index of value you want to read

#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))

struct axes {
	uint16_t x;
	uint16_t y;
	uint16_t z;
};

bool openSPI();
void writeSPI();
void readSPI(struct axes *data_ptr, int range, int i);
void sendToAzure(struct axes *data_ptr);

#ifdef __cplusplus
}
#endif

#endif /* INC_MAIN_H_ */
