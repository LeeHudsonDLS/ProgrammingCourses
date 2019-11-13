//
// Created by jjc62351 on 04/10/2019.
//

#include "Rectangle.h"

Rectangle::Rectangle(int x1, int y1, int x2, int y2):topLeft(x1,y1),bottomRight(x2,y2) {


}

Rectangle::Rectangle(Point& tl, Point& br): topLeft(tl), bottomRight(br) {

}

void Rectangle::f() {
    topLeft.f1();
}