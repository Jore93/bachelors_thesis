/*
 * main.c
 *
 *  Created on: 25.9.2017
 *      Author: jore
 */

#include "main.h"

int main() {
	bool ret;
	int i = 0;
	struct axes *data_ptr, *tmp;

	tmp = calloc(1, sizeof(struct axes));

	if(tmp != NULL) {
		data_ptr = tmp;
	}

	ret = openSPI();

	while(ret && tmp != NULL) {
		writeSPI();
		readSPI(data_ptr, 4, i);
		sendToAzure(data_ptr);
		i++;
		memset(data_ptr, 0, sizeof(struct axes));
	}

	if(tmp != NULL) {
		free(data_ptr);
	}
}


