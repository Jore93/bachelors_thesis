/*
 * main.c
 *
 *  Created on: 25.9.2017
 *      Author: jore
 */

#include "main.h"

int main() {
	bool ret;
	uint16_t *data_ptr, *tmp, n;
	n = 3;
	tmp = malloc((n+1)*sizeof(uint16_t));

	if(tmp != NULL) {
		data_ptr = tmp;
	} else {
		while(tmp != NULL) {
			tmp = calloc(1, (n+1)*sizeof(uint16_t));
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


