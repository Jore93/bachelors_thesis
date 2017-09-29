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
	uint8_t tx[] = {PROD_ID, 0x00, PROD_ID, 0x00};
	static const char *device = "/dev/spidev0.0";
	static uint8_t mode = SPI_MODE_3;
	static uint8_t bits = 8;
	static uint32_t speed = 1000000;	// 1 MHz

	initSPI(&fd, device, mode, bits, speed);
	i = 0;
	printf("Array size: %d\n", ARRAY_SIZE(tx));
	tmp = calloc(1, sizeof(struct axes));
	if(tmp != NULL) {
		data_ptr = tmp;
	}
	writeSPI(fd, tx);
	while(i<5 && tmp != NULL) {
//		delay(43);
//		tx[2] = 0x00; tx[3] = 0x00;
//		writeSPI(fd, tx);
		delay(0.020);
//		tx[2] = PROD_ID; tx[3] = 0x00;
		data_ptr->x = readSPI(fd, tx);
		delay(0.020);
//		tx[0] = PROD_ID; tx[2] = 0x00;
		data_ptr->y = readSPI(fd, tx);
		delay(0.020);
//		tx[2] = PROD_ID; tx[0] = 0x00;
		data_ptr->z = readSPI(fd, tx);
//		delay(0.020);
		sendToAzure(data_ptr);
		i++;
		memset(data_ptr, 0, sizeof(struct axes));
	}

	if(tmp != NULL) {
		free(data_ptr);
	}
}


