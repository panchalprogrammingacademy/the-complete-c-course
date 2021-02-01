// necessary imports
#include <stdio.h>

// merges the two subarrays into one
void merge(int* array, int* aux, int low, int mid, int high){
	// copy the elements to aux array
	for (int i = low; i <= high; ++i) aux[i] = array[i];
	// iterate through array and populate
	int i = low, j = mid + 1, k = low;
	// populate all entries in array
	while(k <= high) 
		// check if left subarray is exhausted
		if (i == mid + 1)			array[k++] = aux[j++];
		// check if right subarray is exhausted
		else if (j == high + 1)		array[k++] = aux[i++];
		// if both subarrays contains elements then compare
		else if (aux[i] <= aux[j])	array[k++] = aux[i++];
		else 						array[k++] = aux[j++];
}
// sorts the array using merge-sort
void merge_sort(int* array, int* aux, int low, int high) {
	// require at least two elements in the array
	if (low < high) {
		// get the middle element
		// DO NOT USE mid = (low + high)/2 OVERFLOWS
		int mid = low + (high - low)/2;
		// sort the left subarray
		merge_sort(array, aux, low, mid);
		// sort the right subarray
		merge_sort(array, aux, mid  + 1, high);
		// merge the two pieces
		merge(array, aux, low, mid, high);
	}
}
// sorts the array using the merge sort algorithm
// NOTE: we could have used built-in qsort function
// we implemented our merge-sort for review!
void sort(int* array, int N){
	// create an auxiliary array of size N
	// for processing
	int aux[N];
	// sort the array using merge-sort
	merge_sort(array, aux, 0, N - 1);
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
	// sort the array
	sort(array, N);
	// compute the mean
	int sum = 0;
	for (int i = 0; i < N; ++i) sum = sum + array[i];
	// report the sum
	printf ("%lf ", (double)sum / N );
	// median depends on the size of the array
	if ( N % 2 != 0) {
		// odd array size has single median
		printf ("%lf\n", (double)array[N/2]);
	} else {
		// average of (N/2 and N/2 - 1) is medians
		printf ("%lf\n", (array[N/2] + array[N/2 - 1])/2.0);
	}
	// successful termination
	return 0;
}