//
// Created by jjc62351 on 04/10/2019.
//

#ifndef COMPOSITION_RECTANGLE_H
#define COMPOSITION_RECTANGLE_H

#include "Point.h"

class Rectangle {
public:
    Rectangle(int x1, int y1, int x2, int y2);
    Rectangle(Point& tl, Point& br);
    void f();
private:
    Point topLeft;
    Point bottomRight;
};


#endif //COMPOSITION_RECTANGLE_H
