#include <stdio.h>
int main() {
	// store the user's input
	int seconds;
	// accept user's input
	scanf ("%d", &seconds);
	// get the number of minutes
	int minutes = seconds / 60;
	seconds = seconds % 60;
	// get the number of hours
	int hours = minutes / 60;
	minutes = minutes % 60;
	// print the results
	printf ("%02d:%02d:%02d\n", hours, minutes, seconds);
	// successful exit
	return 0;
}