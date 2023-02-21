#include "matrix.hpp"
#include "linreg.hpp"
#include <iostream>
#include <cctype>

int main() {
    std::size_t sizeLimit = 11;
    std::cout << sizeLimit << endl;
    Matrix mx;
    for (std::size_t size = 1; size <= sizeLimit; size++) {
        mx = Matrix(size, size);
        mx.randomize();
        std::cout << size << '\t' << abs(mx.det() - mx.fastDet()) << endl;
    }

    return 0;
}