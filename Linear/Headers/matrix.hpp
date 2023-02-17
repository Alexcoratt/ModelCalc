/*
 * matrix.hpp
 *
 *  Created on: Feb 17, 2023
 *      Author: alexsm
 */

#ifndef HEADERS_MATRIX_HPP_
#define HEADERS_MATRIX_HPP_

#include <cctype>
#include "vector.hpp"

using namespace std;

struct Matrix {
	private:
		// Fields
		size_t height_;
		size_t width_;
		double * values;

	public:
		// Constructors
		Matrix(size_t, size_t);
		// Destructor
		~Matrix();
		// Copying
		explicit Matrix(Matrix &);
		// Assigning
		Matrix & operator=(Matrix &);

		// Getting
		double & get(size_t, size_t);
		double get(size_t, size_t) const;

		Vector getRow(size_t) const;
		Vector getCol(size_t) const;

		// Setting
		void resize(size_t, size_t);

		void insertRow(Vector &, size_t = height_);
		void insertCol(Vector &, size_t = width_);

		Vector popRow(size_t = height_);
		Vector popCol(size_t = width_);

		// Math methods
		Matrix operator*(Matrix const &) const;
		Matrix operator*(double const) const;
		Matrix operator*(Vector const &) const;

		Matrix operator/(Matrix const &) const;
		Matrix operator/(double const) const;
		Matrix operator/(Vector const &) const;

		Matrix operator+(Matrix const &) const;
		Matrix operator+(double const) const;

		Matrix operator-(Matrix const &) const;
		Matrix operator-(double const) const;

		Matrix transposed() const;

		double det() const;
		double complement() const;
		double minor() const;
		Matrix minorMatrix(size_t, size_t) const;

		double fastDet() const;
};



#endif /* HEADERS_MATRIX_HPP_ */
