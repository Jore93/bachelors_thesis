/*
 * src_cntrl.c
 *
 *  Created on: 25.9.2017
 *      Author: jore
 */

#include "main.h"

bool openSPI() {
	int ret;
	ret = wiringPiSPISetup(0, 9600);
	pinMode(19, OUTPUT);          // MOSI
	pinMode(21, INPUT);           // MISO
	pinMode(23, GPIO_CLOCK);      // SCLK
	pinMode(24, OUTPUT);          // CE0
//	pinMode(0, OUTPUT);           // RST
	if(ret == 0) {
		return false;
	}
	return true;
}

void writeSPI() {
/*
 *
 *  A single register read requires two 16-bit SPI cycles. The first sequence sets
 *	R/W = 0 and communicates the target address (Bits 15 to 8). Bits 7 to 0 are
 *	don’t care bits for a read DIN sequence. Second 16-bit SPI cycle sends the
 *	actual message to register.
 *
 */
	digitalWrite(12, REC_CTRL);
	digitalWrite(12, WRITE_REG);
	delay(43);		// Sampling time when using SR1 is 42.15 ms
}

void readSPI(struct axes *data_ptr, int range, int i) {
	/* These calculations are for 0g to 70g range, change the value of n depending on what range you are using.
	 *
	 * Range:
	 * 1: 0g to 1g
	 * 2: 0g to 5g
	 * 3: 0g to 20g
	 * 4: 0g to 70g
	 */

	uint16_t acceleration(uint16_t value) {
		// For time mode
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

	struct axes value;

	digitalWrite(12, X_BUF);
	digitalWrite(12, i);
	value.x = digitalRead(13);
	data_ptr->x = acceleration(value.x);

	digitalWrite(12, Y_BUF);
	digitalWrite(12, i);
	value.y = digitalRead(13);
	data_ptr->y = acceleration(value.y);

	digitalWrite(12, Z_BUF);
	digitalWrite(12, i);
	value.z = digitalRead(13);
	data_ptr->z = acceleration(value.z);
}

void sendToAzure(struct axes *data_ptr) {
	// Send data from data_ptr to Azure
	printf("x axis: %d\ny axis: %d\n z axis: %d\n\n", data_ptr->x, data_ptr->y, data_ptr->z);
}

