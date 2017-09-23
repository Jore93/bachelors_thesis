/*
 * cntrl_src.c
 *
 *  Created on: 23.9.2017
 *      Author: jore
 */

#include "main.h"

bool openSPI(){
	int ret;
	ret = wiringPiSPISetup(0,9600);
	if(ret == 0) {
		return false;
	}
	return true;
}
void writeSPI() {
	digitalWrite(12, WRITE_REG);
}
void readSPI(uint8_t *data_ptr) {
	digitalRead(13);
}
void sendToAzure(uint8_t *data_ptr) {

}
