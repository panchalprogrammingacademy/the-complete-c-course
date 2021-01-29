// necessary imports
#include <stdio.h>
#include <stdbool.h>
// checks if the array is palindrome
bool is_palindrome(int* array, int N){
	// start comparing values at end points
	// till we reach to the middle element
	int i = 0, j = N - 1;
	while (i < j) {
		// the value at index i and j 
		// are equidistant from the center
		// and must be equal if array is palindrome
		if (array[i] != array[j])	return false;
		// move to next indices
		i++; j--;
	}
	// the array is palindrome
	return true;
}
// driver function
int main(){
	// stores the number of elements in the array
	int N;
	// accept user's input
	scanf ("%d", &N);
	// create an array of size N
	int array[N];
	// accept the elements of the array
	for (int i = 0; i < N; ++i) scanf ("%d", &array[i]);
	// check if the array is palindrome
	bool result = is_palindrome(array, N);
	// print the appropriate results 
	printf ("%s\n", (result ? "TRUE" : "FALSE"));
	// successful termination
	return 0;
}