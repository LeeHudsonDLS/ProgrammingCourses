//
// Created by jjc62351 on 23/10/2019.
//

#include "B.h"

B::B(int baseVal):
    A(baseVal),
    baseVal(baseVal) {

}

std::string B::printBase(){
    char buffer[255];
    sprintf(buffer,"Value is %d\n",baseVal);
    return buffer;
};