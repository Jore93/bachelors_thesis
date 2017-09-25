/*
 * main.c
 *
 *  Created on: 25.9.2017
 *      Author: jore
 */

#include "main.h"

int main() {
	bool ret;
	uint8_t *data_ptr, *tmp, n = 13;
	tmp = calloc(1, 5*sizeof(char));

	if(tmp != NULL) {
		data_ptr = tmp;
	} else {
		while(tmp != NULL) {
			tmp = calloc(1, n*sizeof(char));
			n--;
		}
	}

	ret = openSPI();

	while(ret && tmp != NULL) {
		writeSPI();
		readSPI(data_ptr, 4);
		sendToAzure(data_ptr);
	}

	if(tmp != NULL) {
		free(data_ptr);
	}
}


