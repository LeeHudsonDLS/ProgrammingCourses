//
// Created by jjc62351 on 04/10/2019.
//

#ifndef COMPOSITION_POINT_H
#define COMPOSITION_POINT_H

#include <iostream>
#include <sstream>

class Point {
public:
    Point(const Point& original);
    Point(int x=0, int y=0);
    std::string display();
private:
    int x;
    int y;

};


#endif //COMPOSITION_POINT_H