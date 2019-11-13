//
// Created by jjc62351 on 22/10/2019.
//

#include <iostream>

#ifndef CASTOPERATORS_TIME_H
#define CASTOPERATORS_TIME_H


class Time {

public:
    Time();
    Time(int mins); // Override (Time) cast operator
    Time(int hrs, int mins);
    operator int(); // Override (int) cast operator
    friend std::ostream operator <<(std::ostream& out,const Time& t);
private:
    int hrs;
    int mins;
};


#endif //CASTOPERATORS_TIME_H
