//
// Created by jjc62351 on 04/10/2019.
//
#include "Point.h"

Point::Point(const Point& original): x(original.x), y(original.y) {}

Point::Point(int x, int y): x(x), y(y) {
}

std::string Point::display() {
    //std::cout << "Point x:" << x << " y: " << y << "\n";
    std::stringstream s;
    s << x << ":" << y << " ";
    return s.str();
}