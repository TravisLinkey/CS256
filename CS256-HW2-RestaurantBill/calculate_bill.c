/*
 * calculate_bill.c
 *
 *  Created on: Apr 10, 2018
 *      Author: travis
 */

#include <stdio.h>


int main() {

	double mealCost = 88.67;
	double tax = 6.75;
	double tipPercent = .2;
	double total;
	double tipAmount;

	total = mealCost + tax + (mealCost*tipPercent);
	tipAmount = mealCost*tipPercent;

	printf("Meal cost: $%.02f \n", mealCost);
	printf("Tax amount: $%.02f \n", tax);
	printf("Tip amount: $%.02f \n", tipAmount);
	printf("Total bill: $%.02f \n", total);

	return 0;
}
