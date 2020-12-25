#include <stdio.h>
int main() {
	// for user's input
	int sales;
	// stores the commission
	double commission = 0.0;
	// accept user's input
	scanf ("%d",  &sales);
	// take decision
	if 		(sales > 30000)		commission = 0.15*sales;
	else if (sales > 22000)		commission = 0.10*sales;
	else if (sales > 12000)		commission = 0.07*sales;
	else if (sales > 5000)		commission = 0.05*sales;
	else 						commission = 0.00*sales;
	// print the result up-to two digits after the decimal point
	printf ("%.2lf\n", commission);
	// successful exit
	return 0;
}