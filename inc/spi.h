/*
 * spi.h
 *
 *  Created on: 27.9.2017
 *      Author: jore
 */

#ifndef INC_SPI_H_
#define INC_SPI_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <time.h>
#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>

#include "reg_def.h"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))

struct axes {
	int16_t x;
	int16_t y;
	int16_t z;
};

void initSPI(int *fd, const char *device, uint8_t mode, uint8_t bits, uint32_t speed);
void writeSPI(int fd, uint8_t *msg);
int16_t readSPI(int fd, uint8_t *msg);
void sendToAzure(struct axes *data_ptr);
uint16_t acceleration(uint16_t value, int range);
void recordingSettings(int fd);
void startRecording(int fd);
void readBuffers(int fd, struct axes *data_ptr);
void delay (unsigned int howLong);


#ifdef __cplusplus
}
#endif

#endif /* INC_SPI_H_ */
