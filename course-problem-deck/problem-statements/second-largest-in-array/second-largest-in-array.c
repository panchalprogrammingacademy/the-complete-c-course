// necessary imports
#include <stdio.h>
#include <stdbool.h>

// returns the index of the second 
// largest element in the array
int second_largest(int* array, int N){
	// first we need to find two indices in the
	// array which contains distinct values
	int i = 0, j = 1;
	while (j < N && array[j] == array[i]) j++;
	// now there are two cases 
	// if j = N then we have exhausted the array
	// and so there is no 2nd max.
	if (j == N)	return -1;
	// now we compare the elements at index i, j
	// to arrange them
	int firstMaxIndex, secondMaxIndex;
	if (array[i] > array[j]) {
		firstMaxIndex = i;
		secondMaxIndex = j;
	} else {
		firstMaxIndex = j;
		secondMaxIndex = i;
	}
	// iterate through remaining elements
	for (int k = j + 1; k < N; ++k){
		// compare with largest element
		if (array[k] > array[firstMaxIndex]) {
			// this element is greater than max.
			// so we update the second max to max.
			// and we update the max. to this element
			secondMaxIndex = firstMaxIndex;
			firstMaxIndex = k;
		} else if (array[k] > array[secondMaxIndex]) {
			// update the index of second max. element
			secondMaxIndex = k;
		}
	}
	// return the index of the secondMaxElement
	return secondMaxIndex;
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
	// get the index of the second largest element
	int index = second_largest(array, N);
	// print the result
	printf ("%d\n", (index != -1 ? array[index] : -1));
	// successful termination
	return 0;
}