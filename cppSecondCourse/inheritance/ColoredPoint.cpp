//
// Created by jjc62351 on 04/10/2019.
//

#include "ColoredPoint.h"
ColoredPoint::ColoredPoint(int x, int y, int color): Point(x,y), color(color) {

}

void ColoredPoint::print() {
    //display();
    std::cout << Point::display() << color << std::endl;
}