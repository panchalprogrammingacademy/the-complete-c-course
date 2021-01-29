// necessary imports
#include <stdio.h>
// driver function
int main(){
	// accept the size of the array
	int N;
	scanf ("%d", &N);
	// create an array of size N
	int array[N];
	// accept elements of the array
	for (int i = 0; i < N; ++i)	scanf("%d", &array[i]);
	// accept the key
	int key;
	scanf ("%d", &key);
	// stores the index
	int index = -1;
	// search for the key in the array
	for (int i = 0; i < N; ++i)
		if (array[i] == key) {
			index = i;
			break;
		}
	// report the index
	printf ("%d\n", index);
	// sucessful termination
	return 0;
}