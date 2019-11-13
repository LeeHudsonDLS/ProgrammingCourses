//
// Created by jjc62351 on 03/10/2019.
//

#ifndef HEAP_TIME_H
#define HEAP_TIME_H

#include <iostream>

class Time {
public:
    Time(int h, int m);
    ~Time();
    void hello();
private:
    int hours;
    int minutes;

};


#endif //HEAP_TIME_H
