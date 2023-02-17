/*
 * Number.hpp
 *
 *  Created on: Feb 16, 2023
 *      Author: alexsm
 */

#ifndef NUMBER_HPP_
#define NUMBER_HPP_

#include <ostream>

struct Number {
	// Constructor
	Number(double = 0);

	// Getting methods
	double & get();
	double get() const;

	// Operators
	Number operator+(Number const &) const;
	Number operator-(Number const &) const;

	private:
		// fields
		double value_;
};


#endif /* NUMBER_HPP_ */
