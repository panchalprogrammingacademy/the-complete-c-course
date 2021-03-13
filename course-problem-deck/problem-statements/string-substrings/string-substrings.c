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
int len(char* string) {
	int size = 0;
	for (int i = 0; string[i] != '\0'; ++i)	size++;
	return size;
}

// prints all possible substrings of a given string
void substrings(char* string) {
	// get the length of the string
	int N = len(string);
	// iterate and print
	// prints of length 1, 2, ..., N
	for (int l = 1; l <= N; ++l){
		// find the end point upto which 
		// we need to iterate
		int bound = N - l;
		// iterate from zero to that specific bound
		for (int i = 0; i <= bound; ++i){
			// print string[i...i+l-1]
			for (int j = i; j < i + l; ++j)
				printf ("%c", string[j]);
			printf ("\n");
		}
	}
}

// driver function
int main(){
	// max. characters are 10
	// one extra space for null-character
	int size = 11;
	// stores the input
	char string[size];
	// accept the input
	_gets(string, size);
	// print result
	substrings(string);
	// successful termination
	return 0;
}
