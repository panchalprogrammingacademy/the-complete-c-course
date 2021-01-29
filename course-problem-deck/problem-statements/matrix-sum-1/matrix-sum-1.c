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
	// stores the sum
	int sum_all = 0; // sum of all elements
	int sum_upp = 0; // sum of upper half elements
	int sum_low = 0; // sum of lower half elements
	int sum_dia = 0; // sum of diagonal elements
	// iterate through matrix
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j){
			// for all elements we add
			sum_all += matrix[i][j];
			// for upper-half
			if (i < j)	sum_upp += matrix[i][j];
			// for lower-half
			if (i > j) sum_low += matrix[i][j];
			// for diagonal
			if (i == j)	sum_dia += matrix[i][j];
		}
	// report the computation results
	printf ("%d %d %d %d\n", sum_all, sum_upp, sum_low, sum_dia);
	// successful termination
	return 0;
}