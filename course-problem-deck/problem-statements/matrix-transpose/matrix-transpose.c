// neccessary imports
#include <stdio.h>
// driver function
int main(){
	// stores the order of the matrices
	int m, n;
	// accept the order of the matrix
	scanf ("%d %d", &m, &n);
	// create matrices
	int matrix[m][n], transpose[n][m];
	// input elements of the matrix
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			scanf ("%d", &matrix[i][j]);
	// populate the transpose matrix
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			transpose[j][i] = matrix[i][j];
	// print the transpose matrix
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j)
			printf ("%d ", transpose[i][j]);
		printf ("\n");
	}
	// successful termination
	return 0;
}