/*
 * main.c
 *
 *  Created on: Apr 12, 2018
 *      Author: travis
 */

double calculateProfit(int, double, double, int);

int main() {

	int numOfShares = 1000;
	double pricePerShareBought = 45.50;
	double commissionPercent = 0.02;

	printf("Bought: \n");
	double totalBought = calculateProfit(numOfShares, pricePerShareBought, commissionPercent,0);

	printf("Sold: \n");
	double pricePerShareSold = 56.90;
	double totalSold = calculateProfit(numOfShares, pricePerShareSold, commissionPercent,1);

	printf("------------------------------------------\n");
	printf("Total profit: $%.02f \n", totalSold - totalBought);


	return 0;
}

double calculateProfit(int numOfShares, double pricePerShare, double commission, int transactionType) {
	double total;

	double costOfShares = numOfShares*pricePerShare;
	double commissionCost = costOfShares*commission;

	if(transactionType == 0)
		printf("	Stock BUY total: $%.02f \n", costOfShares);
	else if (transactionType == 1)
		printf("	Stock SOLD total: $%.02f \n", costOfShares);


	printf("	Commission paid: $%.02f \n", commissionCost);
	total = costOfShares - commissionCost;

	return total;
}


