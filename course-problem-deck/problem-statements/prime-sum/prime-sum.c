#include <stdio.h>
#include <stdbool.h>
#include <math.h>
int main() {
	// store user's input and sum
	int N, sum = 0;
	// accept user's input
	scanf ("%d", &N);
	// stores the number of primes found
	int prime_count = 0;
	// counter takes values from 2
	int counter = 2;
	// iterate till we found N primes
	while (prime_count < N) {
		// get the value of the counter
		int value = counter++;
		// check if valus is prime
		// O(√N) algorithm for primality test
		bool isprime = true;
		int bound = sqrt(value);
		for (int j = 2; j <= bound; ++j)
			if (value % j == 0) {
				isprime = false;
				break;
			}
		// if number is prime then add it
		if (isprime) {
			// increase the number of primes found
			prime_count++;
			// add the value to prime
			sum = sum + value;
		}
	}
	// print the computed sum
	printf ("%d\n", sum);
	// successful exit
	return 0;
}
