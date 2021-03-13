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


// helper function
int indexOf(char ch) {
	// uppercase character 'A'...'Z' maps to 0...25
	// lowercase character 'a'...'z' maps to 26...51
	// digits '0'...'9' maps  to 52...61
	// space maps to 62
	if ('A' <= ch && ch <= 'Z')	return (ch - 'A');
	if ('a' <= ch && ch <= 'z')	return (ch - 'a' + 26);
	if ('0' <= ch && ch <= '9')	return (ch - '0' + 52);
	return 62;
}

// helper function
char characterOf(int index) {
	// 0...25 uppercase
	if (index <= 25)	return ('A' + index);
	// 26...51 lowercase
	if (index <= 51)	return ('a' + index - 26);
	// 52...61 digits
	if (index <= 61)	return ('0' + index - 52);
	// otherwise it maps to space
	return ' ';
}

// helper function
void findFrequency(char* string) {
	// given that string consists of only 
	// lowercase character, uppercase character
	// digits, and space
	// characters are mapped using indexOf
	// total characters = 26 + 26 + 10 + 1 = 63
	int size = 63;
	int freq[size];
	// start with zero frequency for all
	for (int i = 0; i < size; ++i)	freq[i] = 0;
	// iterate through string
	for (int i = 0; string[i] != '\0'; ++i){
		// get the indexing for this character
		int index = indexOf(string[i]);
		// increase the frequency at this index
		freq[index]++;
	}
	// print the frequencies of all characters
	for (int i = 0; i < size; ++i)
		if (freq[i] > 0)	
			printf ("%c:%d\n", characterOf(i), freq[i]);
}

// driver function
int main(){
	// max. size is 1000
	// one extra for null character
	int size = 1001;
	// stores the input
	char string[size];
	// accept the input
	_gets(string, size);
	// process the string
	findFrequency(string);
	// successful termination
	return 0;
}
