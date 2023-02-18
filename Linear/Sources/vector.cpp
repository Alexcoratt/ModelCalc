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
#include <algorithm>
#include <sstream>

using namespace std;

// Constructors
Vector::Vector(size_t size) : size_(size), values_(new double[size]) {
	for (size_t i = 0; i < size_; i++)
		values_[i] = 0;
}
Vector::Vector(size_t size, double * values) : size_(size), values_(values) {}

// Copying
Vector::Vector(Vector & other) : size_(other.size_), values_(new double[size_]){
	for (size_t i = 0; i < size_; i++)
		values_[i] = other.values_[i];
}

// Assigning
Vector & Vector::operator=(Vector & other) {
	if (this != &other) {
		Vector tmp(other);
		swap(tmp);
	}
	return *this;
}

//Destructor
Vector::~Vector() {
	delete [] values_;
	values_ = 0;
}

// Methods

// Getting
double & Vector::get(size_t index) {return values_[index];}
double Vector::get(size_t index) const {return values_[index];}

size_t const Vector::getSize() const {return size_;}

stringstream Vector::toSStream() const {
	stringstream result;
	for (size_t i = 0; i < size_ - 1; i++)
		result << values_[i] << '\t';
	result << values_[size_ - 1];
	return result;
}

// Setting
void Vector::swap(Vector & other) {
	std::swap(size_, other.size_);
	std::swap(values_, other.values_);
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
