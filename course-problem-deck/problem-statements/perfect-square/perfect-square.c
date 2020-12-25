#include <stdio.h>
#include <math.h>
int main() {
	// store user's input
	int N;
	// accept user's input
	scanf ("%d", &N);
	// compute the sqrt
	int sqrtNum = sqrt(N);
	// if sqrt^2 == N then it is a perfect square
	printf ("%s\n", (pow(sqrtNum, 2) == N ? "TRUE" : "FALSE"));
	// successful exit
	return 0;
}