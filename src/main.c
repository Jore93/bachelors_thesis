/*
 * main.c
 *
 *  Created on: 25.9.2017
 *      Author: jore
 */

#include "spi.h"



int main() {
	int i, fd;
	struct axes *data_ptr, *tmp;
	static const char *device = "/dev/spidev0.0";
	static uint8_t mode;
	static uint8_t bits = 8;
	static uint32_t speed = 500000;


	initSPI(&fd, device, mode, bits, speed);

	tmp = calloc(1, sizeof(struct axes));
	if(tmp != NULL) {
		data_ptr = tmp;
	}

	while(i < 10) {//ret && tmp != NULL) {
		writeSPI(fd);
		readSPI(data_ptr, 4, fd);
		sendToAzure(data_ptr);
		i++;
		memset(data_ptr, 0, sizeof(struct axes));
	}

	if(tmp != NULL) {
		free(data_ptr);
	}
}


