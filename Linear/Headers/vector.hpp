/*
 * Vector
 *
 *  Created on: Feb 16, 2023
 *      Author: alexsm
 */

#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <cctype>
#include "number.hpp"

using namespace std;

struct Vector {
	// Constructors
	explicit Vector(size_t);
	Vector(size_t, Number *);

	// Copying
	Vector(Vector &);

	// Assigning
	Vector & operator=(Vector const &);

	// Destructor
	~Vector();

	// Methods

	// Getting
	Number & get(size_t);
	Number get(size_t) const;

	size_t const length() const;

	// Setting
	void swap(Vector &);
	void resize(size_t);

	private:
		// Fields
		size_t size_;
		Number * values_;

};


#endif /* VECTOR_HPP_ */
