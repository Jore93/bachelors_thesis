/*
 * main.c
 *
 *  Created on: 25.9.2017
 *      Author: jore
 */

#include "spi.h"
#include "reg_def.h"


int main() {
	int i, fd, wait;
	uint8_t tx[4] = {0};
	struct axes *data_ptr, *tmp;
	static const char *device = "/dev/spidev0.0";
	static uint8_t mode = SPI_MODE_3;
	static uint8_t bits = 8;
	static uint32_t speed = 1000000;	// 1 MHz

	initSPI(&fd, device, mode, bits, speed);
	i = 0;

	tmp = calloc(1, sizeof(struct axes));
	if(tmp != NULL) {
		data_ptr = tmp;
	}

	// Software reset
	tx[2] = GLOB_CMD;
	writeSPI(fd, tx);
	delay(0.020);
	tx[3] = 0x40;
	writeSPI(fd, tx);
	delay(55);
	tx[3] = 0x00;

	while(i<50 && tmp != NULL) {
		// Tell what to record
		tx[2] = REC_CTRL;
		writeSPI(fd, tx);
		delay(0.020);
		tx[2] = 0x02; tx[3] = 0x32;
		writeSPI(fd, tx);
		delay(0.020);

		// Start recording
		tx[2] = GLOB_CMD; tx[3] = 0x00;
		writeSPI(fd, tx);
		delay(0.020);
		tx[2] = 0x08;
		writeSPI(fd, tx);
		delay(50);

		// Read values from buffers
		tx[2] = X_BUF;
		writeSPI(fd, tx);
		delay(0.020);
		tx[2] = 0x00;
		writeSPI(fd, tx);
		delay(0.020);
		data_ptr->x = readSPI(fd, tx);
		delay(0.020);

		tx[2] = PROD_ID;
		writeSPI(fd, tx);
		delay(0.020);
		tx[2] = 0x00;
		writeSPI(fd, tx);
		delay(0.020);
		data_ptr->y = readSPI(fd, tx);
		delay(0.020);

		tx[2] = Z_BUF;
		writeSPI(fd, tx);
		delay(0.020);
		tx[2] = 0x00;
		writeSPI(fd, tx);
		delay(0.020);
		data_ptr->z = readSPI(fd, tx);
		delay(0.020);

		sendToAzure(data_ptr);
		i++;
		memset(data_ptr, 0, sizeof(struct axes));
	}

	if(tmp != NULL) {
		free(data_ptr);
	}
}


