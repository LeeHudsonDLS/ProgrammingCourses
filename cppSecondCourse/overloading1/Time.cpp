//
// Created by jjc62351 on 02/10/2019.
//

#include "Time.h"

Time::Time():hrs(0),min(0){}
Time::Time(int hrs, int min): hrs(hrs), min(min) {}
// Overriding copy constructor
Time::Time(const Time& t): hrs(t.hrs), min(t.min) {}

Time& Time::operator=(const Time & t) {
    (*this).hrs=t.hrs;
    (*this).min=t.min;
    return *this;
}
Time& Time::operator+=(const Time& t){
    (*this).hrs = t.hrs + (*this).hrs;
    (*this).min = t.min + (*this).min;
    return *this;
};


int Time::getHrs() {return hrs;}
int Time::getMins() { return min;}
void Time::print() {
    std::cout << hrs << ":" << min << std::endl;
}

// Free function, not a member function
Time operator+(const Time& s1,const Time& s2){
    Time result(s1.hrs+s2.hrs,s1.min+s2.min);
    return result;
}