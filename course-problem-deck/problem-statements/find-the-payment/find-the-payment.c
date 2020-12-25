#include <stdio.h>
int main() {
	// store user's input
	int bill, del_charge, prime_mem;
	// accept user's input
	scanf ("%d %d %d", &bill, &del_charge, &prime_mem);
	// stores the payment - initially bill + delivery_charges
	double payment = bill + del_charge;
	// find the payment
	if (bill > 50000) {
		// 100% discount on delivery charges
		payment = payment - 1.00*del_charge;
	} else if (bill > 25000) {
		// check for prime membership
		// for prime members discount is 100% 
		// otherwise discount is 50%
		if (prime_mem == 1)	payment -= 1.00*del_charge;
		else 				payment -= 0.50*del_charge;
	} else if (bill > 10000) {
		// check for prime membership
		// for prime members discount is 25% 
		// otherwise discount is 10%
		if (prime_mem == 1)	payment -= 0.25*del_charge;
		else 				payment -= 0.10*del_charge;		
	} 
	// print the payment - NOTE %g specifier
	printf ("%g\n", payment);
	// successful exit
	return 0;
}