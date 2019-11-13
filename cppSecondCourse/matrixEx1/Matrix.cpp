//
// Created by jjc62351 on 03/10/2019.
//

#include "Matrix.h"


Matrix operator+(const Matrix& l, const Matrix& r){
    Matrix result(l);
    for(int i = 0; i < result.rows; i++){
        for(int j = 0; j < result.colomns; j++){
            result.data[i][j] += r.data[i][j];
        }
    }
    return result;
}

Matrix::Matrix(std::vector<std::vector<int>> data): data(data) {
    colomns = data[0].size();
    rows = data.size();
}

void Matrix::print()
{
    for(auto v: data)
    {
        for(auto i: v)
        {
            std::cout << i << ",";
        }
        std::cout << std::endl;
    }
}