// neccessary imports
#include <stdio.h>
// searches and returns the index of the key
// in the given array of size N
// assumes that the input array is sorted
int binary_search(int* array, int N, int key){
	// maintains the indices
	int low = 0, high = N - 1, mid;
	// iterate through array
	while(low <= high) {
		// compute the index of the middle element
		// DON'T DO [mid = (low+high)/2] OVERFLOWS
		mid = low + (high - low)/2;
		// make comparison
		if (array[mid] == key)		return mid;
		else if (array[mid] < key)	low = mid + 1;
		else 						high = mid - 1;
	}
	// if we are here then we have exhausted the array
	// and we couldn't find the key
	return -1;
}

// driver function
int main(){
	// stores the size of the array
	int N;
	scanf ("%d", &N);
	// create an array of size N
	int array[N];
	// accept the inputs
	for (int i = 0; i < N; ++i) scanf("%d", &array[i]);
	// accept the key
	int key;
	scanf ("%d", &key);
	// search for the key in the array
	int index = binary_search(array, N, key);
	// print the index
	printf ("%d\n", index);
	// successful termination
	return 0;
}