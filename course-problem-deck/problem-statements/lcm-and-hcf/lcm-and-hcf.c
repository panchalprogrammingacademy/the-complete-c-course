#include <stdio.h>
#include <stdbool.h>
int main() {
	// store user's input
	int A, B;
	// accept user's input
	scanf ("%d %d", &A, &B);
	// stores the lcm and hcf
	int lcm = 1, hcf = 1;
	// first we need to find hcf
	// use the modulo technique to find hcf
	// take a copy of origina variables
	int a = A, b = B;
	while (true) {
		if 		(a == 0) {hcf = b; break;}
		else if (b == 0) {hcf = a; break;}
		else if (a < b)		b = b % a;
		else				a = a % b;
	}

	// now lcm is product divided by hcs
	lcm = (A * B) / hcf;

	// print the results
	printf ("%d %d\n", lcm, hcf);
	// successful exit
	return 0;
}