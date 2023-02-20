/*
 * polynome.hpp
 *
 *  Created on: Feb 19, 2023
 *      Author: alexsm
 */

#ifndef HEADERS_POLYNOME_HPP_
#define HEADERS_POLYNOME_HPP_

#include "vector.hpp"
#include "matrix.hpp"
#include <string>

using namespace std;

struct Polynome {
	private:
		size_t rank_;
		Vector ratios_;

	public:
		// Constructors
		Polynome(size_t);
		Polynome(Vector);

		// Getting
		double & get(size_t);
		double get(size_t) const;

		size_t getRank() const;

		string toString() const;

		// Math
		double calculate(double) const;

		void interpolate(Matrix mx);
};


#endif /* HEADERS_POLYNOME_HPP_ */
