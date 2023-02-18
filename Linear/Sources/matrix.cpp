/*
 * matrix.cpp
 *
 *  Created on: Feb 17, 2023
 *      Author: alexsm
 */


#include "matrix.hpp"
#include <cctype>
#include <algorithm>
#include <stdexcept>
#include <sstream>

using namespace std;

// Constructor
Matrix::Matrix(size_t height, size_t width) :
		height_(height), width_(width), values_(new double[height_ * width_]) {
	size_t size = width * height;
	for (size_t i = 0; i < size; i++)
		values_[i] = 0;
}

// Destructor
Matrix::~Matrix() {
	delete [] values_;
	values_ = 0;
}

// Copying
Matrix::Matrix(Matrix & other) :
		height_(other.height_), width_(other.width_), values_(new double[height_ * width_]) {
	size_t const size = width_ * height_;
	for (size_t i = 0; i < size; i++)
		values_[i] = other.values_[i];
}

// Assigning
Matrix & Matrix::operator=(Matrix & other) {
	if (this != &other)
	{
		Matrix tmp(other);
		swap(tmp);
	}
	return *this;
}

// Getting
double & Matrix::get(size_t row, size_t col) {return values_[row * width_ + col];}
double Matrix::get(size_t row, size_t col) const {return values_[row * width_ + col];}

Vector Matrix::getRow(size_t row) const {
	Vector res(width_);
	for (size_t i = 0; i < width_; i++)
		res.get(i) = get(row, i);
	return res;
}

Vector Matrix::getCol(size_t col) const {
	Vector res(height_);
	for (size_t i = 0; i < height_; i++)
		res.get(i) = get(i, col);
	return res;
}

size_t Matrix::getHeight() const {return height_;}
size_t Matrix::getWidth() const {return width_;}

stringstream Matrix::toSStream() const {
	size_t i = 0;
	size_t j = 0;

	stringstream result;

	for (i = 0; i < height_ - 1; i++) {
		for (j = 0; j < width_; j++)
			result << get(i, j) << '\t';
		result << '\n';
	}

	for (j = 0; j < width_; j++)
		result << get(height_ - 1, j) << '\t';

	return result;
}

// Setting
void Matrix::resize(size_t height, size_t width) {
	Matrix tmp(height, width);

	size_t minHeight = height > height_ ? height_ : height;
	size_t minWidth = width > width_ ? width_ : width;
	size_t i = 0;
	size_t j = 0;

	for (i = 0; i < minHeight; i++)
		for (j = 0; j < minWidth; j++)
			tmp.get(i, j) = get(i, j);
	swap(tmp);
}

void Matrix::insertRow(Vector & vector) {insertRow(vector, height_);}
void Matrix::insertRow(Vector & vector, size_t row) {
	if (vector.getSize() != width_)
		throw std::runtime_error("Wrong vector size");

	resize(height_ + 1, width_);
	size_t i = 0;
	size_t j = 0;

	for (j = 0; j < width_; j++) {
		if (row < height_ - 1)
			for (i = height_ - 1; i > row; i--)
				get(i, j) = get(i - 1, j);
		get(row, j) = vector.get(j);
	}
}

void Matrix::insertCol(Vector & vector) {insertCol(vector, width_);}
void Matrix::insertCol(Vector & vector, size_t col) {
	if (vector.getSize() != height_)
		throw std::runtime_error("Wrong vector size");

	resize(height_, width_ + 1);
	size_t i = 0;
	size_t j = 0;

	for (i = 0; i < height_; i++) {
		if (col < width_ - 1)
			for (j = width_ - 1; j > col; j--)
				get(i, j) = get(i, j - 1);
		get(i, col) = vector.get(i);
	}
}

void Matrix::deleteRow() {deleteRow(height_ - 1);}
void Matrix::deleteRow(size_t row) {
	Matrix tmp(height_ - 1, width_);

	size_t i = 0;
	size_t j = 0;

	short delta = 0;

	for (i = 0; i < tmp.height_; i++) {
		if (i >= row)
			delta = 1;
		for (j = 0; j < tmp.width_; j++)
			tmp.get(i, j) = get(i + delta, j);
	}
	swap(tmp);
}

void Matrix::deleteCol() {deleteCol(width_ - 1);}
void Matrix::deleteCol(size_t col) {
	Matrix tmp(height_, width_ - 1);

	size_t i = 0;
	size_t j = 0;

	short delta = 0;

	for (j = 0; j < tmp.width_; j++) {
		if (j >= col)
			delta = 1;
		for (i = 0; i < tmp.height_; i++)
			tmp.get(i, j) = get(i, j + delta);
	}
	swap(tmp);
}

void Matrix::swap(Matrix & other) {
	std::swap(height_, other.height_);
	std::swap(width_, other.width_);
	std::swap(values_, other.values_);
}

// Math methods
Matrix Matrix::operator*(Matrix const & other) const {
	if (width_ != other.height_)
		throw std::runtime_error("Unacceptable sizes");

	Matrix res(height_, other.width_);

	size_t i = 0;
	size_t j = 0;

	for (i = 0; i < res.height_; i++)
		for (j = 0; j < res.width_; j++)
			res.get(i, j) = getRow(i) * other.getCol(j);
	return res;
}
