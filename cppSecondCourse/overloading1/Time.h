//
// Created by jjc62351 on 02/10/2019.
//

#include <iostream>

#ifndef OVERLOADING1_TIME_H
#define OVERLOADING1_TIME_H


class Time {
    friend Time operator+(const Time& s1,const Time& s2);
public:
    Time();
    Time(int hrs, int min);
    Time(const Time& t);
    Time& operator=(const Time& t);
    Time& operator+=(const Time& t);
    int getHrs();
    int getMins();
    void print();
private:
    int hrs;
    int min;
};


#endif //OVERLOADING1_TIME_H
