//
// Created by jjc62351 on 04/10/2019.
//

#ifndef FUNCTION_NAME_OVERLOADING_COLOREDPOINT_H
#define FUNCTION_NAME_OVERLOADING_COLOREDPOINT_H

#include "Point.h"

class ColoredPoint: public Point {

public:
    ColoredPoint(int x, int y, int color);
    void print();
private:
    int color;
};


#endif //FUNCTION_NAME_OVERLOADING_COLOREDPOINT_H
