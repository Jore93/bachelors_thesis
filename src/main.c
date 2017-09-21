/*
 * main.c
 *
 *	This is main for my Bachelor's thesis work with RasPi and ADIS 16227 vibration sensor.
 *	Code is runs vibration sensor connected to RasPi 3 and then send data to cloud via 5GTN
 *  Created on: 31.8.2017
 *      Author: Jore
 */

#include "main.h"

int main(void) {
	// Open SPI
	open_SPI();
	while(true) {
	// Send command to start recording data

	// Read data from SPI

	// Send data to Azure
	}
	return 0;
}
