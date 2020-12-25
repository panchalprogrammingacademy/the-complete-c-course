#include <stdio.h>
int main() {
	// store user's input
	int N;
	// accept user's input
	scanf ("%d", &N);
	// stores the factorial - for overflow situation
	// we used the large data type
	unsigned long long int factorial = 1;
	// compute the factorial
	for (int i = 1; i <= N; ++i)	factorial *= i;
	// print the factorial
	printf ("%d! = %llu\n", N, factorial);
	// successful exit
	return 0;
}