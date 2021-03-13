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
	for (int i = 0; string[i] != '\0'; ++i) size++;
	return size;
}

// returns the index of str2 in str1
int findIndex(char* str1, char* str2) {
	// find the length of both the strings
	int size1 = len(str1), size2 = len(str2);
	// iterate to find str2 in str1
	for (int i = 0; i < size1; ++i){
		int left = i;
		int right = 0;
		// as long as indices are valid and character matches
		// we move to compare the next character
		while (left < size1 && right < size2 
				&& str1[left] == str2[right]){
			left++;
			right++;
		}
		// if right string is exhausted
		// that means it was found at index i
		if (right == size2) return i;
	}
	// if we are here then str2 do not exist in str1
	return -1;
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
	printf ("%d\n", findIndex(str1, str2));
	// successful termination
	return 0;
}
