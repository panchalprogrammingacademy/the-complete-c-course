#include <stdio.h>
int main() {
	// store user's input
	int N;
	// accept user's response
	scanf ("%d", &N);
	// take decision
	printf ("%s\n", (N % 2 == 0 ? "EVEN" : "ODD"));
	// successful exit
	return 0;
}