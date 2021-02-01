// necessary imports
#include <stdio.h>
// rotates the array to left by d units
void rotate_left(int* array, int N, int d) {
	// NOTE
	// [1] d can cross the size of N
	// e.g. for array of size 10 
	// 102 rotations effectively means 2 
	// [2] rotating an array means shifting
	// e.g. 1 2 3 4 5 6 7 8 9 10
	// rotating it by 3 units means
	// take first 3 elements and throw them to end
	// 4 5 6 7 8 9 10 1 2 3

	// actual code 
	d = d % N;
	// auxiliary array to take copy
	int aux[d];
	// take copy of first d elements
	for (int i = 0; i < d; ++i)
		aux[i] = array[i];
	// shift all elements to left by d units
	for (int i = 0; i + d < N; ++i)
		array[i] = array[i + d];
	// copy the aux array into last d-positions
	for (int i = 0, j = N - d; i < d; ++i, ++j)
		array[j] = aux[i];
}
// driver function
int main() {
	// stores the size of the array
	int N;
	// accept user's input
	scanf ("%d", &N);
	// create an array of size N
	int array[N];
	// acept user's input
	for (int i = 0; i < N; ++i) scanf ("%d", &array[i]);
	// number of units to rotate
	int d;
	// accept user's response
	scanf ("%d", &d);
	// rotate array to left by d units
	rotate_left(array, N, d);
	// print the content of the array
	for (int i = 0; i < N; ++i)
		printf ("%d ", array[i]);
	printf ("\n");
	// successful termination
	return 0;
}