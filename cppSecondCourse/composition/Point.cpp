//
// Created by jjc62351 on 04/10/2019.
//
#include <iostream>
#include "Point.h"

Point::Point(const Point& original): x(original.x), y(original.y) {}

Point::Point(int x, int y): x(x), y(y) {
    std::cout << "Point x:" << x << " y: " << y << "\n";
}

void Point::f1(){

}