// neccessary imports
#include <stdio.h>
// inputs a matrx of order (rows, cols) from console
// NOTE: size is declared before the matrix for ease
// so that we can use the size in the matrix order
// Alternatively we could have used int**
// a method like (int matrix[rows][cols], int rows, int cols)
// won't work because rows and cols are undefined
void input_matrix(int rows, int cols, int matrix[rows][cols]){
	// iterate and populate
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
			scanf ("%d", &matrix[i][j]);
}

// computes the product of the matrices
void matrix_product(int m1, int n1, int A[m1][n1], int m2, int n2, int B[m2][n2], int C[m1][n2]) {
	// assumes that n1 = m2
	// then only product is possible
	for (int i = 0; i < m1; ++i)
		for (int j = 0; j < n2; ++j){
			// start with zero entry
			int sum = 0;
			// compute the row/col element wise product
			for (int k = 0; k < n1; ++k)
				sum = sum + A[i][k]*B[k][j];
			// update the entry
			C[i][j] = sum;
		}
}

// driver function
int main(){
	// stores the order of the matrices
	int m1, n1, m2, n2;
	// accept the order of the matrix
	scanf ("%d %d %d %d", &m1, &n1, &m2, &n2);
	// create matrices
	int A[m1][n1], B[m2][n2], C[m1][n2];
	// populate matrices
	input_matrix(m1, n1, A);
	input_matrix(m2, n2, B);
	// compute the matrix product
	matrix_product(m1, n1, A, m2, n2, B, C);
	// print the matrix 
	for (int i = 0; i < m1; ++i){
		for (int j = 0; j < n2; ++j)
			printf ("%d ", C[i][j]);
		printf ("\n");
	}
	// successful termination
	return 0;
}