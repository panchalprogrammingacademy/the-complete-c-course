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
void findFrequency(char* string) {
	// given that string consists of only lowercase character
	// map lowercase character to indices
	// 'a': 0, 'b': 1, ...., 'z': 25
	int freq[26];
	// start with zero frequency for all
	for (int i = 0; i < 26; ++i)	freq[i] = 0;
	// iterate through string
	for (int i = 0; string[i] != '\0'; ++i){
		// get the indexing for this character
		int index = (string[i] - 'a');
		// increase the frequency at this index
		freq[index]++;
	}
	// print the frequencies of all characters
	for (int i = 0; i < 26; ++i)
		if (freq[i] > 0)	
			printf ("%c:%d\n", (i + 'a'), freq[i]);
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
