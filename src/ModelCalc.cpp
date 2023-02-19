//============================================================================
// Name        : ModelCalc.cpp
// Author      : Alexander Smirnov
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================


#include "vector.hpp"
#include "matrix.hpp"
#include "linreg.hpp"
#include <cctype>
#include <iostream>
#include <fstream>

using namespace std;


int main(int argc, char ** argv) {
	Matrix mx;
	size_t h = 0;
	size_t w = 2;

	if (argc <=1) {
		cout << "Enter number of the points:\t";
		cin >> h;

		w = 2;
		mx = Matrix(h, w);

		size_t i = 0;
		size_t j = 0;

		cout << "Enter points (format: x y)" << endl;
		for (i = 0; i < h; i++) {
			cout << "Point " << (i + 1) << ":\t";
			for (j = 0; j < w; j++)
				cin >> mx.get(i, j);
		}
	}
	else {
		ifstream file(argv[1]);
		string line;
		string tmp;

		if (file.is_open()) {
			file >> h;
			mx = Matrix(h, w);

			size_t i = 0;
			size_t j = 0;

			for (i = 0; i < h; i++) {
				for (j = 0; j < w; j++)
					file >> mx.get(i, j);
				cout << "Point " << (i + 1) << ":\t" <<
						mx.getRow(i).toString() << endl;
			}
		}
		else {
			cout << "Unable to read the file " << argv[1] << endl;
			return -1;
		}
	}

	cout << "--------------" << endl << endl;

	LinReg lr(mx);

	cout <<
			"Func :\t" << lr.toString() << endl <<
			"S^2 :\t" << lr.s2(mx) << endl <<
			"sig^2 :\t" << lr.sig2(mx) << endl <<
			"R^2 :\t" << lr.r2(mx) << endl;

	return 0;
}
