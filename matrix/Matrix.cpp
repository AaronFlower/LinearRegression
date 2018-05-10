#include "Matrix.h"

/**
 * Public functions
 */
Matrix::Matrix(initializer_list<double> init_list) {
    m = init_list.size();
    n = 1;
    allocSpace();

    size_t j = 0;
    for (auto it:init_list) {
        *(*(mat + j) + 0) = it;
        ++j;
    }
}

Matrix::Matrix(initializer_list<initializer_list<double>> init_list) {
    m = init_list.size();
    n = (*init_list.begin()).size();
    allocSpace();
    auto it = init_list.begin();
    size_t i, j;
    for (i = 0; i < m; ++i) {
        j = 0;
        for (auto ele:*it) {
            *(*(mat + i) + j) = ele;
            ++j;
        }
        ++it;
    }

    std::cout << "\nAfter Initialization: ";
    for (i = 0; i < m; ++i) {
        for (j =0; j < n; ++j) {
            std::cout << *(*(mat + i) + j) << "\t";
        }
    }
}


Matrix::size Matrix::shape() {
    return Matrix::size(m, n);
}

Matrix::~Matrix() {
    for (size_t i = 0; i < m; ++i) {
        delete[] mat[i];
    }
    delete[] mat;
}

vector<double> Matrix::flatten() {
    vector<double> v;
    for (size_t i = 0; i < m; ++i) {
        for (size_t j = 0; j < n; ++j) {
            v.push_back(*(*(mat + i) + j));
        }
    }
    return v;
}

/**
 * Private functions
 */
void Matrix::allocSpace() {
	mat = new double*[m];
	for (size_t i = 0; i < m; ++i) {
		mat[i] = new double[n];
	}
}



