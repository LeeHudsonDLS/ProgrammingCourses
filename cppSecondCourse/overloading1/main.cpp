#include <iostream>
#include "Time.h"
using namespace std;



int main() {
    Time t; // Uses default CTOR
    Time t1(4,15);
    Time t2(2,50);
    Time t3(t1); // Uses CTOR that takes Time
    t1.print();
    t2.print();
    t1 += t2;
    t1.print();
    cout << "here" << endl;

}