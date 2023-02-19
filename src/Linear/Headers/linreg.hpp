/*
 * linreg.hpp
 *
 *  Created on: Feb 19, 2023
 *      Author: alexsm
 */

#ifndef HEADERS_LINREG_HPP_
#define HEADERS_LINREG_HPP_

#include "polynome.hpp"
#include "matrix.hpp"

// Model of linear regression
struct LinReg : Polynome {
	public:
		// Constructors
		LinReg(Matrix const &);

		void defPoly(Matrix const &); // defines coeffs of the polynome by given mx

		// Evaluation metrics
		double s2(Matrix const &);	// Mean Squared Error s^2 = 1/(n-2) * E^n_i=1((y_i^cap - y_i)^2)
		double sig2(Matrix const &);
		double r2(Matrix const &);	// R Squared
};


#endif /* HEADERS_LINREG_HPP_ */
