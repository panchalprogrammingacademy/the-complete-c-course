#include <stdio.h>
#include <math.h>
int main(){
	// store user's input
	int N;
	// stores the number of digits
	int digits = 0;
	// stores the computed number
	int computed = 0;
	// stores the copy of the number
	int value; 
	// accept user's input
	scanf ("%d", &N);

	// take a copy of number
	value = N;
	// count the number of digits
	while (value > 0) {
		digits++;
		value /= 10;
	}

	// take a copy of number
	value = N;
	// compute each number raise to the power
	// number of digits
	while (value > 0) {
		computed = computed + pow(value % 10, digits);
		value /= 10;
	}


	// take decision and print results
	printf ("%s\n", (computed == N ? "TRUE" : "FALSE"));
	// successful exit
	return 0;
}