/*
 * linreg.cpp
 *
 *  Created on: Feb 19, 2023
 *      Author: alexsm
 */

#include "linreg.hpp"
#include <cmath>

using namespace std;

LinReg::LinReg(Matrix const & mx) : Polynome(1) {
	defPoly(mx);
}

void LinReg::defPoly(Matrix const & mx) {
	Vector x = mx.getCol(0);
	Vector y = mx.getCol(1);
	size_t n = mx.getHeight();
	double xExpected = x.sum() / n;
	double yExpected = y.sum() / n;

	get(1) =
			(x * y / n - xExpected * yExpected) /
			(x * x / n - xExpected * xExpected);
	get(0) = yExpected - get(1) * xExpected;
}

double LinReg::s2(Matrix const & mx) {
	double res = 0;
	size_t n = mx.getHeight();

	for (size_t i = 0; i < n; i++) {
		res += pow(calculate(mx.get(i, 0)) - mx.get(i, 1), 2);
	}
	return res / (n - 2);
}

double LinReg::sig2(Matrix const & mx) {
	Vector y = mx.getCol(1);
	size_t n = mx.getHeight();

	return y * y / n - pow(y.sum() / n, 2);
}

double LinReg::r2(Matrix const & mx) {
	double top = 0;
	double bot = 0;
	size_t n = mx.getHeight();
	double yExpected = mx.getCol(1).sum() / n;

	for (size_t i = 0; i < n; i++) {
		top += pow(calculate(mx.get(i, 0)) - yExpected, 2);
		bot += pow(mx.get(i, 1) - yExpected, 2);
	}

	return top / bot;
}

