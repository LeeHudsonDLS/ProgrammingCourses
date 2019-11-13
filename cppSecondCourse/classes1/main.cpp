#include <iostream>
#include <string>
#include "Point.h"
using namespace std;


// Can't init in the class definition
int main() {

    Point p1("Point1",100,200);
    Point p2("Point2",200,400);
    Point p3("Point3",300,600);
    p1.moveBy(5,5);
    p2.moveBy(6,6);
    p3.moveBy(7,7);
    p1.display();
    p2.display();
    p3.display();
    cout << Point::getCount() << endl;

}