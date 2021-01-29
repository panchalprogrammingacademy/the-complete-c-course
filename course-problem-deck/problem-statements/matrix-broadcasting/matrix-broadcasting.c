// neccessary imports
#include <stdio.h>
#include <stdbool.h>
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
bool matrix_broadcast_sum(int m1, int n1, int A[m1][n1], int m2, int n2, int B[m2][n2]) {
	// take decision based on size of B
	if (m2 == 1 && n2 == 1) {
		// B is a singleton matrix
		// so will be added to all elements of A
		int singleton = B[0][0];
		for (int i = 0; i < m1; ++i)
			for (int j = 0; j < n1; ++j)
				A[i][j] += singleton;
		// operation suceeded
		return true;
	} else if (m2 == 1) {
		// B is a row vector so it will be 
		// added to rows of A
		// now check if number of column matches
		if (n1 != n2)	return false;
		// number of column matches so we proceed
		for (int i = 0; i < m1; ++i)
			for (int j = 0; j < n1; ++j)
				A[i][j] += B[0][j];
		// operation succeded
		return true;
	} else if (n2 == 1) {
		// B is column vector so it will be 
		// added to columns of A
		// now check if number of rows matches
		if (m1 != m2)	return false;
		// number of rows matches so we proceed
		for (int j = 0; j < n1; ++j)
			for (int i = 0; i < m1; ++i)
				A[i][j] += B[i][0];
		// operation succeeded
		return true;
	} else if (m1 == m2 && n1 == n2){
		// both the matrices have same order
		// so we procced to add B to A elememnt wise
		for (int i = 0; i < m1; ++i)
			for (int j = 0; j < n1; ++j)
				A[i][j] += B[i][j];
		// operation succeeded
		return true;
	}
	// operation could not be performed
	return false;
}

// driver function
int main(){
	// stores the order of the matrices
	int m1, n1, m2, n2;
	// accept the order of the matrix
	scanf ("%d %d %d %d", &m1, &n1, &m2, &n2);
	// create matrices
	int A[m1][n1], B[m2][n2];
	// populate matrices
	input_matrix(m1, n1, A);
	input_matrix(m2, n2, B);
	// compute the broadcast sum
	bool success = matrix_broadcast_sum(m1, n1, A, m2, n2, B);
	// check if operation succeeded
	if (success) {
		// print the matrix 
		for (int i = 0; i < m1; ++i){
			for (int j = 0; j < n1; ++j)
				printf ("%d ", A[i][j]);
			printf ("\n");
		}		
	} else {
		// failed to perform operation
		printf ("Error\n");
	}
	// successful termination
	return 0;
}