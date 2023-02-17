//============================================================================
// Name        : ModelCalc.cpp
// Author      : Alexander Smirnov
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================


#include "vector.hpp"
#include <cctype>
#include <iostream>

using namespace std;


int main() {
	size_t size = 10;
	Vector nums(size);
	nums.get(3) = 10;
	for (size_t i = 0; i < size; i++)
		cout << nums.get(i) << endl;
	cout << endl;

	nums.resize(5);
	size = nums.size();
	nums.get(1) = -2;
	for (size_t i = 0; i < nums.size(); i++)
		cout << nums.get(i) << endl;

	cout << nums.get(1) + nums.get(3);
	return 0;
}
