/*
 * ocean_levels.c
 *
 *  Created on: Apr 10, 2018
 *      Author: travis
 */


#include <stdio.h>

double calculate_yearly(double, int);

int main() {

	double risingRate = 1.5;   // units = mm per year

	printf("Ocean's level will rise %.01f mm in %d years\n", calculate_yearly(risingRate, 5), 5);
	printf("Ocean's level will rise %.01f mm in %d years\n", calculate_yearly(risingRate, 7), 7);
	printf("Ocean's level will rise %.01f mm in %d years\n", calculate_yearly(risingRate, 10), 10);

	return 0;
}

double calculate_yearly(double rate, int years)
{
	return (rate*years);
}
