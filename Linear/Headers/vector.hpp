/*
 * Vector
 *
 *  Created on: Feb 16, 2023
 *      Author: alexsm
 */

#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <cctype>
#include <sstream>
#include <string>

using namespace std;

struct Vector {
	private:
		// Fields
		size_t size_;
		double * values_;

	public:
		// Constructors
		explicit Vector(size_t);
		Vector(size_t, double *);

		// Copying
		Vector(Vector &);

		// Assigning
		Vector & operator=(Vector &);

		// Destructor
		~Vector();

		// Getting
		double & get(size_t);
		double get(size_t) const;

		size_t getSize() const;

		string toString() const;

		// Setting
		void swap(Vector &);
		void resize(size_t);

		// Math methods
		double operator*(Vector const &) const;

		Vector operator+(Vector const &) const;
		Vector operator-(Vector const &) const;

		double length() const;

		double sum() const;
};


#endif /* VECTOR_HPP_ */
