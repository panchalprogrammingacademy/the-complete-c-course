#include <stdio.h>
int main() {
	// for user's input
	int a, b, c;
	// accept three space separated integers
	scanf("%d %d %d", &a, &b, &c);
	// given that a, b, c are distinct!
	// take decision
	if (a < b && a < c){
		// a is the smallest
		// compare b and c
		if (b < c)	printf ("%d %d %d\n", a, b, c);
		// otherwise c < b
		else 		printf ("%d %d %d\n", a, c, b);
	} else if (b < a && b < c) {
		// b is the smallest
		// compare a and c
		if (a < c)	printf ("%d %d %d\n", b, a, c);
		// otherwise c < a
		else		printf ("%d %d %d\n", b, c, a);
	} else {
		// c is the smallest
		// compare a and b
		if (a < b)	printf ("%d %d %d\n", c, a, b);
		// otherwise b < a
		else		printf ("%d %d %d\n", c, b, a);
	}

	// successful exit
	return 0;
}