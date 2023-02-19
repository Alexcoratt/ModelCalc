/*
 * polynome.cpp
 *
 *  Created on: Feb 19, 2023
 *      Author: alexsm
 */


#include "polynome.hpp"
#include "vector.hpp"
#include <cctype>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

Polynome::Polynome(size_t rank) : rank_(rank), ratios_(Vector(rank_ + 1)) {}
Polynome::Polynome(Vector ratios) : rank_(ratios.getSize() - 1), ratios_(ratios) {}

double & Polynome::get(size_t index) {return ratios_.get(index);}
double Polynome::get(size_t index) const {return ratios_.get(index);}

string Polynome::toString() const {
	stringstream res;
	res << "y = ";
	double ratio = 0;

	for (size_t i = 0; i <= rank_; i++) {
		ratio = ratios_.get(i);
		if (ratio < 0)
			res << '-';
		else if (i > 0)
			res << " + ";

		res << abs(ratio);
		if (i > 1)
			res << "x^" << i;
		else if (i > 0)
			res << 'x';
	}
	return res.str();
}

double Polynome::calculate(double arg) const {
	double res = 0;
	for (size_t i = 0; i <= rank_; i++)
		res += ratios_.get(i) * pow(arg, i);
	return res;
}
