/*
 * vector.cpp
 *
 *  Created on: Feb 16, 2023
 *      Author: alexsm
 */


#include "vector.hpp"
#include <cctype>
#include <stdexcept>
#include <cmath>

using namespace std;

// Constructors
Vector::Vector(size_t size) : size_(size), values_(new double[size]) {}
Vector::Vector(size_t size, double * values) : size_(size), values_(values) {}

// Copying
Vector::Vector(Vector & other) : size_(other.size_), values_(new double[size_]){
	for (size_t i = 0; i < size_; i++)
		values_[i] = other.values_[i];
}

// Assigning
Vector & Vector::operator=(Vector const & other) {
	if (this != &other) {
		size_ = other.size_;
		Vector(size_).swap(*this);
	}
	return *this;
}

//Destructor
Vector::~Vector() {
	delete [] values_;
}

// Methods

// Getting
double & Vector::get(size_t index) {return values_[index];}
double Vector::get(size_t index) const {return values_[index];}

size_t const Vector::size() const {return size_;}

// Setting
void Vector::swap(Vector & other) {
	size_t const tmpSize = size_;
	size_ = other.size_;
	other.size_ = tmpSize;

	double * const tmpValues = values_;
	values_ = other.values_;
	other.values_ = tmpValues;
}

void Vector::resize(size_t newSize) {
	if (size_ != newSize) {
		Vector tmp(newSize);
		size_t minSize = size_ > newSize ? newSize : size_;
		for (size_t i = 0; i < minSize; i++)
			tmp.values_[i] = values_[i];
		swap(tmp);
	}
}

// Math methods
double Vector::operator*(Vector const & other) const {
	if (size_ != other.size_)
		throw std::runtime_error("Differently sized vectors");

	double result = 0;
	for (size_t i = 0; i < size_; i++)
		result += values_[i] * other.values_[i];
	return result;
}

Vector Vector::operator+(Vector const & other) const {
	if (size_ != other.size_)
		throw std::runtime_error("Differently sized vectors");

	Vector result(size_);
	for (size_t i = 0; i < size_; i++)
		result.values_[i] = values_[i] + other.values_[i];
	return result;
}

Vector Vector::operator-(Vector const & other) const {
	if (size_ != other.size_)
		throw std::runtime_error("Differently sized vectors");

	Vector result(size_);
		for (size_t i = 0; i < size_; i++)
			result.values_[i] = values_[i] + other.values_[i];
		return result;
}

/*
Vector Vector::crossProduct(Vector const & other) const {

}
*/

double Vector::length() const {
	return(std::sqrt(*this * *this));
}
