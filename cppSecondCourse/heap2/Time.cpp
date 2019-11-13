//
// Created by jjc62351 on 03/10/2019.
//

#include "Time.h"

Time::Time(int h, int m): hours(h),minutes(m) {}
Time::~Time(){ std::cout << "DTOR Called" << std::endl;}
void Time::hello() { std::cout << "Hello" << std::endl;}