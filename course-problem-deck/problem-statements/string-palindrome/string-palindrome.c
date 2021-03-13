// necessary imports
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
// assumes that the string is null-terminated
int len(char* string){
	int size = 0;
	for (int i = 0; string[i] != '\0'; ++i) size++;
	return size;
}

// helper function
bool isPalindrome(char* string){
	// find the length of the string
	int length = len(string);
	// iterate and compare
	for (int i = 0, j = length - 1; i < j; ++i, --j)
		// if there is a mismatch then string is not palindrome
		if (string[i] != string[j])	return false;
	// if we are here then string is palindrome
	return true;
}

// driver function
int main(){
	// max. 1000 characters
	// one extra for null character
	int size = 1001;
	// stores the input
	char string[size];
	// accept the input
	_gets(string, size);
	// check if palindrome
	printf ("%s\n", isPalindrome(string) ? "True" : "False");
	// successful termination
	return 0;
}
