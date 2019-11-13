//
// Created by jjc62351 on 03/10/2019.
//

#ifndef MATRIXEX1_MATRIX_H
#define MATRIXEX1_MATRIX_H

#include <vector>
#include <iostream>

class Matrix {
    friend Matrix operator+(const Matrix& l, const Matrix& r);
public:
    Matrix(std::vector<std::vector<int>> data);
    void print();

private:
    std::vector<std::vector<int>> data;
    //Shape of matrix
    int colomns;
    int rows;
};


#endif //MATRIXEX1_MATRIX_H
