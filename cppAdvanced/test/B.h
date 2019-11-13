//
// Created by jjc62351 on 23/10/2019.
//

#include "A.h"
#include "C.h"
#include <string>
#ifndef TEST_B_H
#define TEST_B_H


class B : public A {
public:
    B(int baseVal);
    std::string printBase();
private:
    int baseVal;
    C myCClass;

};


#endif //TEST_B_H
