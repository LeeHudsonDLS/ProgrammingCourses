//
// Created by jjc62351 on 02/10/2019.
//
#include <iostream>
#include <string>
using namespace std;

#ifndef CLASSES1_POINT_H
#define CLASSES1_POINT_H

class Point{
public:
    static int getCount();
    Point(const string& name, int x0, int y0);

    void display();
    void moveBy(int dX, int dY);
private:
    static int count;
    string name;
    int x,y;
};


#endif //CLASSES1_POINT_H
