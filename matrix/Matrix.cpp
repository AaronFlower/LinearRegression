#include "Matrix.h"
#include <cassert>

/**
 * Public functions
 */
Matrix::Matrix(){}

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
        assert(n == (*it).size());
        j = 0;
        for (auto ele:*it) {
            *(*(mat + i) + j) = ele;
            ++j;
        }
        ++it;
    }
}


Matrix::size Matrix::shape() const noexcept {
    return Matrix::size(m, n);
}

Matrix::~Matrix() {
    freeSpace();
}

Matrix& Matrix::operator= (const Matrix& rmat) {
    size s = rmat.shape();
    if (m != s.first || n != s.second) reallocSpace(s.first, s.second);

    for (size_t i =0; i < m; ++i) {
        for (size_t j = 0; j < n; ++j) {
            *(*(mat + i) + j) = rmat(i, j);
        }
    }
    return *this;
}

Matrix& Matrix::operator= (initializer_list<double> init_list) {
    size_t lm = init_list.size();
    if (m != lm || n != 1) reallocSpace(lm, 1);
   
    auto it = init_list.begin();
    for (size_t i = 0; i < lm; ++i) {
        *(*(mat + i) + 0) = *it++; 
    }
       
    return *this;
}
Matrix& Matrix::operator= (initializer_list<initializer_list<double>> init_list) {
    size_t lm = init_list.size();
    size_t ln = (*init_list.begin()).size();
    if (lm != m || ln != n) {
       reallocSpace(lm, ln); 
    }

    auto it = init_list.begin();
    size_t i, j;
    for (size_t i = 0; i < lm; ++i) {
        j = 0;
        for (auto ele:*it) {
            *(*(mat + i) + j) = ele; 
            ++j;
        }
        ++it;
    }
    return *this;
}

vector<double> Matrix::flatten() const noexcept {
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

void Matrix::reallocSpace (size_t newM, size_t newN) {
    freeSpace();
    m = newM;
    n = newN;
    allocSpace();
}

void Matrix::freeSpace () {
    if (m > 0) {
        for (size_t i = 0; i < m; ++i) {
            if (n > 0) delete[] mat[i];
        }
        delete[] mat;
    }
}



