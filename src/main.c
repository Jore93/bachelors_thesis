/*
 * main.c
 *
 *  Created on: 23.9.2017
 *      Author: jore
 */

#include "main.h"

int main() {
	bool ret;
	uint8_t data_ptr;
	// Init and open SPI
	ret = openSPI();
	if(ret) {
		while(true) {
		// Send data to sensor
			void writeSPI();
		// Read data from sensor
			void readSPI(uint8_t *data_ptr);
		// Send data to Azure via 5G
			void sendToAzure(uint8_t *data_ptr);
		}
	}
}
