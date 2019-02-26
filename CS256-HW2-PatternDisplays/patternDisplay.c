/*
 * patternDisplay.c

 *
 *  Created on: Apr 10, 2018
 *      Author: travis
 */

#include <stdio.h>

int main() {

		int i = 0;
		int j = 0;

	for(i = 0; i < 11; i++) {
		for(j = 0; j < i; j++)
			printf("+");
		printf("\n");
	}

	printf("\n");

	for(i = 0; i < 10; i++) {
		for(j = 10; j > i; j--)
			printf("+");
		printf("\n");
	}

	return 0;
}

