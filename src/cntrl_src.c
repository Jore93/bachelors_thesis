/*
 * src_cntrl.c
 *
 *  Created on: 25.9.2017
 *      Author: jore
 */

#include "spi.h"

static void pabort(const char *s) {
	perror(s);
	abort();
}

void initSPI(int *fd, const char *device, uint8_t mode, uint8_t bits, uint32_t speed) {
	*fd = open(device, O_RDWR);
	if (*fd < 0)
		pabort("Can't open device");


	int ret;
	// SPI mode
	ret = ioctl(*fd, SPI_IOC_WR_MODE, &mode);
	if (ret == -1)
		pabort("Can't set SPI mode");

	ret = ioctl(*fd, SPI_IOC_RD_MODE, &mode);
	if (ret == -1)
		pabort("Can't get SPI mode");

	// Bits per word
	ret = ioctl(*fd, SPI_IOC_WR_BITS_PER_WORD, &bits);
	if (ret == -1)
		pabort("Can't set bits per word");

	ret = ioctl(*fd, SPI_IOC_RD_BITS_PER_WORD, &bits);
	if (ret == -1)
		pabort("Can't get bits per word");

	// Max speed Hz
	ret = ioctl(*fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);
	if (ret == -1)
		pabort("Can't set max speed Hz");

	ret = ioctl(*fd, SPI_IOC_RD_MAX_SPEED_HZ, &speed);
	if (ret == -1)
		pabort("Can't get max speed Hz");

}

void writeSPI(int fd, uint8_t *tx) {
/*
 *
 *  A single register read requires two 16-bit SPI cycles. The first sequence sets
 *	R/W = 0 and communicates the target address (Bits 15 to 8). Bits 7 to 0 are
 *	don’t care bits for a read DIN sequence. Second 16-bit SPI cycle sends the
 *	actual message to register.
 *
 */
	int ret;
	static uint8_t bits = 8;
	static uint32_t speed = 1000000;
	static uint16_t delay;

	uint8_t rx[ARRAY_SIZE(tx)] = {0, };

	struct spi_ioc_transfer tr = {
		.tx_buf = (unsigned long)tx,
		.rx_buf = (unsigned long)rx,
		.len = ARRAY_SIZE(tx),
		.delay_usecs = delay,
		.speed_hz = speed,
		.bits_per_word = bits,
	};

	ret = ioctl(fd, SPI_IOC_MESSAGE(1), &tr);
	if(ret < 1)
		pabort("Cant send SPI message");
}

uint16_t readSPI(int fd, uint8_t *tx) {
	uint16_t value;
	int ret;
	static uint8_t bits = 8;
	static uint32_t speed = 1000000;

	uint8_t rx[ARRAY_SIZE(tx)] = {0, };

	struct spi_ioc_transfer tr = {
		.tx_buf = (unsigned long)tx,
		.rx_buf = (unsigned long)rx,
		.len = ARRAY_SIZE(tx),
		.speed_hz = speed,
		.bits_per_word = bits,
	};

	ret = ioctl(fd, SPI_IOC_MESSAGE(1), &tr);
	value = (rx[0] << 8) | rx[1];

	for(ret=0;ret<ARRAY_SIZE(tx);ret++) {
		printf("%.2X ", rx[ret]);
	}
	printf("\n");

	if(ret==-1)
		pabort("Can't read SPI");
	return value;
}

void sendToAzure(struct axes *data_ptr) {
	// Send data from data_ptr to Azure
	printf("x axis: %d\ny axis: %d\nz axis: %d\n\n", data_ptr->x, data_ptr->y, data_ptr->z);
}

uint16_t acceleration(uint16_t value, int range) {
	/* These calculations are for 0g to 70g range, change the value of n depending on what range you are using.
	 *
	 * Range:
	 * 1: 0g to 1g
	 * 2: 0g to 5g
	 * 3: 0g to 20g
	 * 4: 0g to 70g
	 */

	uint16_t data, n;
	if(range == 1) {
		n = 0.0305;
	}
	else if(range == 2) {
		n = 0.1526;
	}
	else if(range == 3) {
		n = 0.6104;
	}
	else if(range == 4) {
		n = 2.3842;
	}
	else {
		n = 0;
	}

	if(value < 0x8000) {
		data = value * n;
	}
	else if(value > 0x7FFF) {
		data = -(0xFFFF - value -1) * n;
	}
	else {
		data = 0;
	}
	return data;
}


