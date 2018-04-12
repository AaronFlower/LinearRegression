#include "Matrix.h"

/**
 * Public functions
 */
Matrix::Matrix(size_t m, size_t n):m(m), n(n) {
	allocSpace();
	memset(mat, 0, m * n);
}

Matrix::Matrix():Matrix(1, 1){}

/**
 * Private functions
 */
void Matrix::allocSpace() {
	mat = new double*[m];
	for (size_t i = 0; i < n; ++i) {
		mat[i] = new double[n];
	}
}



