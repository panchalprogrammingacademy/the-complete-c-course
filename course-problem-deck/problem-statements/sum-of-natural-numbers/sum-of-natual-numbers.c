#include <stdio.h>
int main() {
	// store user's input
	int N;
	// accept user's input
	scanf ("%d", &N);
	// stores the sum
	unsigned long long int sum = 0;
	// compute the sum
	for (int i = 0; i <= N; ++i)	sum = sum + i;
	// print the sum
	printf ("%llu\n", sum);
	// successful exit
	return 0; 
}