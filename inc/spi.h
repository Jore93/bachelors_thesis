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

#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))

struct axes {
	uint16_t x;
	uint16_t y;
	uint16_t z;
};

void initSPI(int *fd, const char *device, uint8_t mode, uint8_t bits, uint32_t speed);
void writeSPI(int fd);
void readSPI(struct axes *data_ptr, int range, int fd);
void sendToAzure(struct axes *data_ptr);

#ifdef __cplusplus
}
#endif

#endif /* INC_SPI_H_ */
