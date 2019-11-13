//
// Created by jjc62351 on 02/10/2019.
//
#include "Point.h"



int Point::count = 0;
// Don't put static in the implementation
int Point::getCount(){
    return count;
}
/* Use reference to avoid another copy, Has to be const
 as a string is a const char*
 Initialisation before curly brackets
 */
Point::Point(const string& name, int x0, int y0):name(name),x(x0),y(y0)
{
    count++;
}
void Point::display(){
    cout << x << "'" << y << "'" << name << endl;
}
void Point::moveBy(int dX, int dY){
    x = x+dX;
    y = y+dY;
}