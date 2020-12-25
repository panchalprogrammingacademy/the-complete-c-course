#include <stdio.h>
int main() {
	// store user's input
	int N;
	// accept user's input
	scanf ("%d", &N);
	// take a copy of the number
	int value = N;
	// stores the reversed number
	int reversed = 0;
	// compute the reveres number
	while (value > 0) {
		reversed = reversed * 10 + (value % 10);
		value = value / 10;
	}
	// print appropariate value
	printf ("%s\n", (reversed == N ? "TRUE" : "FALSE"));
	// successful exit
	return 0;
}