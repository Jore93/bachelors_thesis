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
	static uint8_t mode = SPI_MODE_3;
	static uint8_t bits = 8;
	static uint32_t speed = 1000000;	// 1 MHz

	i = 0;

	tmp = calloc(1, sizeof(struct axes));
	if(tmp != NULL) {
		data_ptr = tmp;
		initSPI(&fd, device, mode, bits, speed);
	}

	while(/*i<5 &&*/ tmp != NULL) {
		recordingSettings(fd);
		startRecording(fd);
		readBuffers(fd, data_ptr);
		sendToAzure(data_ptr);
		i++;
		memset(data_ptr, 0, sizeof(struct axes));
	}

	if(tmp != NULL) {
		free(data_ptr);
	}
}


