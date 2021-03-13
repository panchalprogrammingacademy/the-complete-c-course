// necessary imports
#include <stdio.h>
#include <stdlib.h>

// helper function
// null-terminated string 
// removes the newline character from the end
void _gets(char* string, int max_size) {
	// get the string from user
	// size + 1 because last newline character will be replaced
	fgets(string, max_size + 1, stdin);
	// find the length of the string
	int size = 0;
	for (int i = 0; string[i] != '\0'; ++i) size++;
	// at index size - 1 we have \n
	// replace that \n with \0
	string[size - 1] = '\0';
}


// finds the length of the string
// assumes that the string is null-terminated
int len(char* string) {
	int size = 0;
	for (int i = 0; string[i] != '\0'; ++i) size++;
	return size;
}

// driver function
int main(){
	// max. characters are 1000
	// one extra space for null character
	int size = 1001;
	// stores the input
	char string[size];
	// accept the input
	_gets(string, size);
	// find and print the length of the string
	printf ("%d\n", len(string));
	// successful termination
	return 0;
}
