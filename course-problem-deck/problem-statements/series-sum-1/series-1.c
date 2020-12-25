#include <stdio.h>
int main() {
	// store user's input
	int N;
	// stores the sum
	double sum = 0.0;
	// accept user's input
	scanf ("%d", &N);
	// compute series sum
	// i takes care of number of terms 0, 1, .. N - 1
	// num takes care of numerator 2, 5, 8, ...
	// den takes care of denominator 9, 13, 17, ...
	// mul takes care of sign = 1, -1, 1, -1, ...
	for (int i = 0, num = 2, den = 9, mul = 1; i < N; 
			i++, num += 3, den += 4, mul *= -1)
			sum = sum + mul*((double)num / den);
	// print the sum to console
	printf ("%.2lf\n", sum);
	// successful exit
	return 0;
}