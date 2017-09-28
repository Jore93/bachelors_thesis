/*
 * main.c
 *
 *  Created on: 25.9.2017
 *      Author: jore
 */

#include "spi.h"
#include "reg_def.h"


int main() {
	int i, fd;
	struct axes *data_ptr, *tmp;
	uint8_t tx[] = {REC_CTRL, 0x00, 0x02, 0x32};
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

	while(i<10 && tmp != NULL) {
		writeSPI(fd, tx);
		tx[0] = X_BUF; tx[1] = 0x00; tx[2] = 0x00; tx[3] = 0x00;
		data_ptr->x = readSPI(fd, tx);
		tx[0] = Y_BUF; tx[1] = 0x00; tx[2] = 0x00; tx[3] = 0x00;
		data_ptr->y = readSPI(fd, tx);
		tx[0] = Z_BUF;; tx[1] = 0x00; tx[2] = 0x00; tx[3] = 0x00;
		data_ptr->z = readSPI(fd, tx);
		tx[0] = REC_CTRL; tx[1] = 0x00; tx[2] = 0x02; tx[3] = 0x32;
		sendToAzure(data_ptr);
		i++;
		memset(data_ptr, 0, sizeof(struct axes));
	}

	if(tmp != NULL) {
		free(data_ptr);
	}
}


