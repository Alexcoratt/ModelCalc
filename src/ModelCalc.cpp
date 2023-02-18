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
	size_t size = 10;
	Vector nums(size);
	nums.get(0) = 10;
	cout << nums.toSStream().str() << endl;

	nums.resize(3);
	size = nums.getSize();
	nums.get(1) = -2;
	cout << nums.toSStream().str() << endl;

	cout << endl;

	Matrix mx(3, 3);
	cout << mx.toSStream().str() << endl << endl;

	mx.get(1, 1) = -2.3;
	cout << mx.toSStream().str() << endl << endl;

	mx.insertRow(nums); // @suppress("Ambiguous problem")
	cout << mx.toSStream().str() << endl << endl;

	mx.deleteRow(2); // @suppress("Ambiguous problem")
	mx.deleteCol(1);
	cout << mx.toSStream().str() << endl << endl;

	return 0;
}
