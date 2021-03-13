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
bool isVowel(char ch) {
	switch(ch){
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			return true;
		default:
			return false;
	}
}

// driver function
int main() {
	// given max. length of 1000
	// one extra space of null-character
	int size = 1001;
	// stores the input
	char text[size]; 
	// accept the input
	_gets(text, size);
	// counts the number of consonants and vowels
	int consonants = 0, vowels = 0;
	// iterate through string
	for (int i = 0; text[i] != '\0'; ++i)
		if (isVowel(text[i]))	vowels++;
		else					consonants++;
	// print the stats
	printf ("vowels= %d, consonants= %d\n", vowels, consonants);
	// successful termination
	return 0;
}