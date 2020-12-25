#include <stdio.h>
int main() {
	// store user's input
	int N;
	// stores the sum - avoid overflow!
	unsigned long long int sum = 0;
	// stores the terms
	unsigned long long int firstTerm = 0, secondTerm = 1;
	// accept user's response
	scanf ("%d", &N);
	// take decision
	if 		(N == 0)	sum = 0;
	else if (N == 1)	sum = 0;
	else if (N == 2)	sum = 1;
	else {
		// sum of first two terms
		sum = 1;
		// stores the next term
		unsigned long long int thirdTerm;
		// start adding next terms
		for (int i = 3; i <= N; ++i){
			thirdTerm = firstTerm + secondTerm;
			sum += thirdTerm;
			firstTerm = secondTerm;
			secondTerm = thirdTerm;
		}
	}

	// print the sum
	printf ("%llu\n", sum);
	// successful exit
	return 0;
}