// neccessary imports
#include <stdio.h>
// driver function
int main(){
	// stores the order of the matrix
	int m, n;
	// accept the order of the matrix
	scanf ("%d %d", &m, &n);
	// create a matrix of order (m,n)
	int matrix[m][n];
	// populate matrix
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			scanf ("%d", &matrix[i][j]);
	// compute the row-wise sum and print
	for (int i = 0; i < m; ++i){
		// compute the sum for ith row
		int sum = 0;
		// iterate through this row
		for (int j = 0; j < n; ++j)
			sum = sum + matrix[i][j];
		// report the sum
		printf ("%d ", sum);
	}
	// next line as per output requirement
	printf ("\n");
	// compute the column-wise sum and print
	for (int j = 0; j < n; ++j) {
		// compute the sum for jth column
		int sum = 0;
		// iterate through jth row
		for (int i = 0; i < m; ++i)
			sum = sum + matrix[i][j];
		// report the sum
		printf ("%d ", sum);
	}
	// formatting
	printf ("\n");
	// successful termination
	return 0;
}