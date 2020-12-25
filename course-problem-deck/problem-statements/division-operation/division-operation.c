#include <stdio.h>
int main() {
	// store user's input
	int A, B;
	// accept user's input 
	// two space separated integers
	scanf ("%d %d", &A, &B);
	// compute and print the result
	// note the %g format specifier
	printf ("%g\n", (double)A / B);
	// successful exit
	return 0;
}