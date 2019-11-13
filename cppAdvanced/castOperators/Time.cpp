//
// Created by jjc62351 on 22/10/2019.
//

#include "Time.h"
Time::Time():hrs(0),mins(0) {}
Time::Time(int mins):hrs(mins/60),mins(mins%60) {}
Time::Time(int hrs, int mins):hrs(hrs),mins(mins) {}

Time::operator int() {
    // Don't need the "this->"
    return this->hrs*60 + this->mins;
}