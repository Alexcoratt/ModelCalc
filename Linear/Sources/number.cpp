/*
 * number.cpp
 *
 *  Created on: Feb 16, 2023
 *      Author: alexsm
 */

#include "number.hpp"

Number::Number(double value) : value_(value) {}

double & Number::get() {return value_;}
double Number::get() const {return value_;}

// Operators
Number Number::operator+(Number const & other) const {
	return Number(get() + other.get());
}

