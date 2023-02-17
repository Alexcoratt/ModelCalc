/*
 * vector.cpp
 *
 *  Created on: Feb 16, 2023
 *      Author: alexsm
 */


#include "vector.hpp"
#include <cctype>

using namespace std;

// Constructors
Vector::Vector(size_t size) : size_(size), values_(new Number[size]) {}
Vector::Vector(size_t size, Number * values) : size_(size), values_(values) {}

// Copying
Vector::Vector(Vector & other) : size_(other.size_), values_(new Number[size_]){
	for (int i = 0; i < size_; i++)
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
Number & Vector::get(size_t index) {return values_[index];}
Number Vector::get(size_t index) const {return values_[index];}

size_t const Vector::length() const {return size_;}

// Setting
void Vector::swap(Vector & other) {
	size_t const tmpSize = size_;
	size_ = other.size_;
	other.size_ = tmpSize;

	Number * const tmpValues = values_;
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
