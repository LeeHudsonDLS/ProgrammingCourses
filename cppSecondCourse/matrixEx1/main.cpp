#include <iostream>
#include "Matrix.h"
int main() {
    Matrix m1{ {{11,12,13},
                    {21,22,23},
                    {31,32,33},
                    {41,42,43}} };
    Matrix m2{ {{2,3,4},
                    {5,6,7},
                    {9,8,7},
                    {10,2,4}} };

    Matrix m = m1 + m2;
    m.print();
    return 0;
}