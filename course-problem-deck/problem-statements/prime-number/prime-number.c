#include <stdio.h>
#include <stdbool.h>
int main() {
	// store user's input
	int N;
	// accept user's input
	scanf ("%d", &N);
	// compute the sqrt
	int sqrtNum = sqrt(N);
	// stores true if number is prime
	bool isprime = true;
	// O(√N) algorithm for primality test
	for (int i = 2; i <= sqrtNum; ++i)
		if (N % i == 0)	 {
			// found a factor for this number
			isprime = false;
			break;
		}
	printf ("%s\n",  (isprime ? "TRUE" : "FALSE"));
	// successful exit
	return 0;
}