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

	uint8_t tx[] = {0x00, 0x00, PROD_ID, 0x00};

	while(i<5 && tmp != NULL) {
/*		writeSPI(fd, tx);
		delay(0.020);
		writeSPI(fd, tx);
		delay(0.020);
		tx[2] = 0x02; tx[3] = 0x32;
		writeSPI(fd, tx);
		delay(0.020);
		writeSPI(fd, tx);
		delay(43);
*/
		tx[2] = X_BUF; tx[3] = 0x00;
		writeSPI(fd, tx);
		delay(0.020);
		data_ptr->x = readSPI(fd, tx);
		delay(0.020);

		tx[2] = Y_BUF;
		writeSPI(fd, tx);
		delay(0.020);
		data_ptr->y = readSPI(fd, tx);
		delay(0.020);

		tx[2] = Z_BUF;
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


