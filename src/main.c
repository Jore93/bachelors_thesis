/*
 * main.c
 *
 *  Created on: 25.9.2017
 *      Author: jore
 */

#include "spi.h"

static void pabort(const char *s) {
	perror(s);
	abort();
}


int main() {
	int i, ret, fd;
	struct axes *data_ptr, *tmp;
	ret = 0;
	static const char *device = "/dev/spidev0.0";
	static uint8_t mode;
	static uint8_t bits = 8;
	static uint32_t speed = 500000;

	fd = open(device, O_RDWR);
	if (fd < 0)
		pabort("Can't open device");


	// SPI mode
	ret = ioctl(fd, SPI_IOC_WR_MODE, &mode);
	if (ret == -1)
		pabort("Can't set SPI mode");

	ret = ioctl(fd, SPI_IOC_RD_MODE, &mode);
	if (ret == -1)
		pabort("Can't get SPI mode");

	// Bits per word
	ret = ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &bits);
	if (ret == -1)
		pabort("Can't set bits per word");

	ret = ioctl(fd, SPI_IOC_RD_BITS_PER_WORD, &bits);
	if (ret == -1)
		pabort("Can't get bits per word");

	// Max speed Hz
	ret = ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);
	if (ret == -1)
		pabort("Can't set max speed Hz");

	ret = ioctl(fd, SPI_IOC_RD_MAX_SPEED_HZ, &speed);
	if (ret == -1)
		pabort("Can't get max speed Hz");

	printf("SPI mode: %d\n", mode);
	printf("Bits per word: %d\n", bits);
	printf("Max speed: %d Hz (%d KHz)\n", speed, speed/1000);




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


