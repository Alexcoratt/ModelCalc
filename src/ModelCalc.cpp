//============================================================================
// Name        : ModelCalc.cpp
// Author      : Alexander Smirnov
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================


#include "vector.hpp"
#include "matrix.hpp"
#include <cctype>
#include <iostream>

using namespace std;


int main() {
	size_t size = 2;
	Matrix mx = Matrix(size, size + 1);
	//mx.randomize();

	mx.get(0, 0) = 1;
	mx.get(0, 1) = 0;
	mx.get(0, 2) = 0;

	mx.get(1, 0) = 0;
	mx.get(1, 1) = 1;
	mx.get(1, 2) = 0;

	cout << mx.crossProduct().toString() << endl;

	return 0;
}
