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
#include <sstream>
#include <string>

using namespace std;

struct Matrix {
	private:
		// Fields
		size_t height_;
		size_t width_;
		double * values_;

	public:
		// Constructors
		Matrix();
		Matrix(size_t, size_t);
		// Destructor
		~Matrix();
		// Copying
		Matrix(Matrix const &);
		Matrix(Matrix const *);
		// Assigning
		Matrix & operator=(Matrix const &);
		Matrix * operator=(Matrix const *);

		// Getting
		double & get(size_t, size_t);
		double get(size_t, size_t) const;

		Vector getRow(size_t) const;
		Vector getCol(size_t) const;

		size_t getHeight() const;
		size_t getWidth() const;

		string toString() const;

		// Setting
		void resize(size_t, size_t);

		void insertRow(Vector const &);
		void insertRow(Vector const &, size_t);

		void insertCol(Vector const &);
		void insertCol(Vector const &, size_t);

		void deleteRow();
		void deleteRow(size_t);

		void deleteCol();
		void deleteCol(size_t);

		void swap(Matrix &);

		void randomize();

		// Math methods
		Matrix operator*(Matrix const &) const;
		Matrix operator*(double) const;
		Vector operator*(Vector const &) const;

		Matrix operator/(Matrix const &) const;
		Matrix operator/(double) const;

		Matrix operator+(Matrix const &) const;
		Matrix operator+(double) const;

		Matrix operator-(Matrix const &) const;
		Matrix operator-(double) const;

		Matrix transposed() const;

		double det() const;	// accurate way O(n!)
		double complement(size_t, size_t) const;
		double minor(size_t, size_t) const;
		Matrix minorMatrix(size_t, size_t) const;

		double fastDet() const;	// fast way O(n)

		Matrix inverted() const;

		Vector crossProduct() const; // calculates cross product by rows of the matrix
};



#endif /* HEADERS_MATRIX_HPP_ */
