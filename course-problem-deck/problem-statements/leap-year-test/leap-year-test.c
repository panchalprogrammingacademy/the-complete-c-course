#include <stdio.h>
int main() {
	// store user's input
	int year;
	// accept user's input
	scanf("%d", &year);
	// take decision based on value
	if 		(year % 4 != 0)		printf ("FALSE\n");
	else if (year % 100 != 0)	printf ("TRUE\n");
	else if (year % 400 != 0)	printf ("FALSE\n");
	else						printf ("TRUE\n");
	// successful exit
	return 0;
}