#include <iostream>
#include "Time.h"

using std::cout;

std::ostream operator <<(std::ostream& out,const Time& t){
    out << t.hrs << ":" << t.mins ;
}

int main() {
    Time t;
    Time t1(3,45);
    Time t2(2,20);
    int i;
    i = (int)t1; // Doing t1.operator int() => t1 is *this
    t = (Time)i;
    cout << t; // operator<<(cout,t), returns cout
    cout << std::endl;
    t = t1 + t2; // Calls unintended casts, ideally make int() explicit
    cout << t << std::endl;
}