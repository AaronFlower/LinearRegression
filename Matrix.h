#ifndef LINEAR_REGRESSION_MATRIX_H__
#define LINEAR_REGRESSION_MATRIX_H__

#include <cstddef> // size_t
#include <iostream>

using std::size_t;
using std::ostream;
using std::istream;

class Matrix {
	public:
		Matrix();
		Matrix(size_t m, size_t n);
		Matrix(const Matrix &);
		Matrix& operator=(const Matrix&);
		~Matrix();

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

		// vector
		static double dotProduct(const Matrix&, const Matrix&);
	 		
	private:
		size_t m;
		size_t n;
		double **mat;

		void allocSpace();
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

