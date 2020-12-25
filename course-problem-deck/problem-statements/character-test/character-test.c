#include <stdio.h>
int main() {
	// for user's input
	char ch;
	// accept user's input
	scanf ("%c",  &ch);
	// take decision
	if 		('a' <= ch && ch <= 'z')	printf ("LOWER\n");
	else if ('A' <= ch && ch <= 'Z')	printf ("UPPER\n");
	else if ('0' <= ch && ch <= '9')	printf ("DIGIT\n");
	else 								printf ("SPECIAL\n");
	// successful exit
	return 0;
}