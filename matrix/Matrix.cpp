#include "Matrix.h"
#include <cassert>
#include <cmath>

/**
 * Public functions
 */
Matrix::Matrix(){}

Matrix::Matrix(vec v) {
    m = v.size();
    n = 1;
    allocSpace();
    size_t j = 0;
    for (auto it:v) {
        *(*(mat + j) + 0) = it;
        ++j;
    }
}

Matrix::Matrix(vvec vv) {
    m = vv.size();
    n = (*vv.begin()).size();
    allocSpace();
    auto it = vv.cbegin();
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

Matrix::Matrix(iilist init_list) {
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

Matrix::Matrix(ilist init_list):Matrix(vec(init_list)) {}

Matrix::Matrix(const Matrix& cmat) {
   size s = cmat.shape();
   if (s.first != m || s.second != n) reallocSpace(s.first, s.second);

   for (size_t i = 0; i < m; ++i) {
      for (size_t j = 0; j < n; ++j) {
         *(*(mat + i) + j) = cmat(i, j); 
      }
   }
}

Matrix::size Matrix::shape() const noexcept {
    return Matrix::size(m, n);
}

Matrix::~Matrix() {
    freeSpace();
}

Matrix& Matrix::operator= (const Matrix& rmat) {
    if (this != &rmat) {
        size s = rmat.shape();
        if (m != s.first || n != s.second) reallocSpace(s.first, s.second);

        for (size_t i =0; i < m; ++i) {
            for (size_t j = 0; j < n; ++j) {
                *(*(mat + i) + j) = rmat(i, j);
            }
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

Matrix& Matrix::operator+=(const Matrix& rmat) {
    size rs = rmat.shape();
    assert(rs.first == m && rs.second == n);
    for (size_t i = 0; i < m; ++i) {
        for(size_t j = 0; j < n; ++j) {
            *(*(mat + i) + j) += rmat(i, j);
        }
    }

    return *this;
}

Matrix& Matrix::operator-=(const Matrix& rmat) {
    size rs = rmat.shape();
    assert(rs.first == m && rs.second == n);
    for (size_t i = 0; i < m; ++i) {
        for(size_t j = 0; j < n; ++j) {
            *(*(mat + i) + j) -= rmat(i, j);
        }
    }
    return *this;
}

Matrix& Matrix::operator*=(double scalar) {
    for (size_t i = 0; i < m; ++i) {
        for(size_t j = 0; j < n; ++j) {
            *(*(mat + i) + j) *= scalar;
        }
    }
    return *this;
}

Matrix& Matrix::operator^=(int exponent) {
    for (size_t i = 0; i < m; ++i) {
        for(size_t j = 0; j < n; ++j) {
           double v = *(*(mat + i) + j); 
           *(*(mat + i) + j) = std::pow(v, exponent);
        } 
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

/**
 * friend functions
 */

Matrix operator^(const Matrix& mat, double exponent) {
    Matrix newM = mat;
    Matrix::size s = mat.shape();
    for (size_t i = 0; i < s.first; ++i) {
        for (size_t j =0; j < s.second; ++j) {
          newM(i, j) = std::pow(newM(i, j), exponent); 
        }
    }
    return newM; 
}
