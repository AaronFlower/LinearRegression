#ifndef LINEAR_REGRESSION_MATRIX_H__
#define LINEAR_REGRESSION_MATRIX_H__

#include <cstddef> // size_t
#include <vector>
#include <iostream>

using std::size_t;
using std::ostream;
using std::istream;
using std::vector;
using std::initializer_list;
using std::pair;

class Matrix {
	public:
        using size = pair<size_t, size_t>;
        using vec = vector<double>;
        using vvec = vector<vec>;
        using ilist = initializer_list<double>;
        using iilist = initializer_list<ilist>;

        Matrix();
        Matrix(vec);
        Matrix(vvec);
        Matrix(ilist);
        Matrix(iilist);
		Matrix(const Matrix &);

		~Matrix();
		Matrix& operator=(const Matrix&);
		Matrix& operator=(ilist);
		Matrix& operator=(iilist);
		Matrix& operator=(vec);
		Matrix& operator=(vvec);

	    double& operator()(size_t i, size_t j) { return mat[i][j];}
		const double& operator()(size_t i, size_t j) const { return mat[i][j];}

		Matrix& operator+=(const Matrix&);
		Matrix& operator-=(const Matrix&);
		Matrix& operator*=(double);
		Matrix& operator/=(double);
		Matrix& operator^=(int);


		friend ostream& operator<<(ostream &, const Matrix&);
		friend istream& operator<<(istream &, Matrix&);
		friend Matrix operator+(const Matrix&, const Matrix&);
		friend Matrix operator-(const Matrix&, const Matrix&);
		friend Matrix operator*(const Matrix&, const Matrix&);
		friend Matrix operator*(const Matrix&, double);
		friend Matrix operator*(double, const Matrix&);
		friend Matrix operator/(const Matrix&, double);


		void swapRows(size_t, size_t);
		Matrix transpose();
		Matrix inverse();

        vector<double> flatten() const noexcept;
        size shape() const noexcept; 

		// vector
		static double dotProduct(const Matrix&, const Matrix&);
	 		
	private:
		size_t m = 0;
		size_t n = 0;
		double **mat;

		void allocSpace();
        void reallocSpace(size_t, size_t);
        void freeSpace();
};

ostream& operator<<(ostream &, const Matrix&);
istream& operator<<(istream &, Matrix&);
Matrix operator+(const Matrix&, const Matrix&);
Matrix operator-(const Matrix&, const Matrix&);
Matrix operator*(const Matrix&, const Matrix&);
Matrix operator*(const Matrix&, double);
Matrix operator*(double, const Matrix&);
Matrix operator/(const Matrix&, double);

#endif

