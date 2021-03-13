// necessary imports
#include <stdio.h>
#include <stdbool.h>
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


// helper function
bool isLower(char ch) {
	return ('a' <= ch && ch <= 'z');
}

// helper function
bool isAllLower(char* text) {
	// iterate through string
	for (int i = 0; text[i] != '\0'; ++i)
		if (!isLower(text[i]))	return false;
	// if we are here then all characters were lowercase
	return true;
}

// driver function
int main(){
	// max. characters are 1000
	// one extra space for null character
	int size = 1001;
	// stores the input
	char text[size]; 
	// accept input
	_gets(text, size);
	// print result
	printf ("%s\n", isAllLower(text) ? "True" : "False");
	// successful termination
	return 0;
}
