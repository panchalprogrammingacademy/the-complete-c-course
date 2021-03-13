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

// checks if two strings are anagrams
// assumes that strings consists of lowercase characters
bool areAnagrams(char* str1, char* str2) {
	// two strings are anagrams if they have the 
	// same frequency of every character 
	// stores the frequency of characters in str1
	int freq1[26];
	// stores the frequency of characters in str2
	int freq2[26];
	// start with zero frequency of every character
	for (int i = 0; i < 26; ++i)
		freq1[i] = freq2[i] = 0;
	// populate frequencies
	for (int i = 0; str1[i] != '\0'; ++i) freq1[str1[i] - 'a']++;
	for (int i = 0; str2[i] != '\0'; ++i) freq2[str2[i] - 'a']++;
	// compare the frequencies
	for (int i = 0; i < 26; ++i)
		if (freq1[i] != freq2[i])
			return false;
	// if we are here then strings are anagrams
	return true;
}
// driver function
int main(){
	// max. characters are 1000
	// one extra space for null-character
	int size = 1001;
	// stores the input
	char str1[size], str2[size];
	// accept the input
	_gets(str1, size);
	_gets(str2, size);
	// print result
	printf ("%s\n", areAnagrams(str1, str2)  ? "True" : "False");
	// successful termination
	return 0;
}
