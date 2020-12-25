#include <stdio.h>
int main() {
	// store user's input and sum
	int N, sum = 0;
	// accept user's input
	scanf ("%d", &N);
	// compute the sum of (1^2) + (1^2 + 2^2) + (1^2 + 2^2 + 3^2)
	// i takes care of number of terms 0, 1, ..., N - 1
	for (int i = 0; i < N; ++i) {
		// for a given i the subsequence has (i + 1) terms
		// i.e. 1, 2, 3, 4, ...
		// stores the number of terms
		int terms = i + 1;
		// stores the temporary sum
		int tempSum = 0;
		for (int j = 1; j <= terms; ++j) tempSum += j*j;
		// add the tempSum to actual sum
		sum += tempSum;
	}
	// print the computed sum
	printf ("%d\n", sum);
	// successful exit
	return 0;
}


// // efficient version
// // we can reuse the sum of ith term
// // to compute the sum of (i+1)th term
// // i takes care of number of terms 1, 2, ..., N 
// // stores the termSum
// int termSum = 0;
// // stores the series sum
// int seriesSum = 0;
// for (int i = 1; i <= N; ++i) {
// 	// to every term we take the previous term sum
// 	// and add the square of i to get sum of this term
// 	termSum += i*i;
// 	seriesSum += termSum;
// }
