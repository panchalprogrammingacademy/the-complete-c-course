#include <stdio.h>
int main() {
	// store user's input
	int N;
	// accept user's input
	scanf ("%d", &N);
	// find out the divisors
	for (int i = 1; i <= N; ++i)
		if (N % i == 0)	printf ("%d ", i);
	// successful exit
	return 0;
}