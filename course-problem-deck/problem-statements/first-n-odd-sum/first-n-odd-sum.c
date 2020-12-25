#include <stdio.h>
int main() {
	// store user's input and sum
	int N, sum = 0;
	// accept user's input
	scanf ("%d", &N);
	// compute sum
	// i takes cares of number of terms 0, 1, 2,... N - 1
	// t takes care of odd terms 1, 3, 5, 7, ...
	for (int i = 0, t = 1; i < N; ++i, t += 2) sum += t;
	// print the sum to console
	printf ("%d\n", sum);
	// successful exit
	return 0;
}