//
// Created by jjc62351 on 23/10/2019.
//
#include <iostream>
#include <string>

#ifndef controller_H
#define controller_H

class Controller {
public:
    Controller(std::string ipAddress);

    virtual void writeToHardware();
    virtual void writeToHardware2();

    char inString_[255];
    char outString_[255];
    std::string ipAddress;
protected:
    int genericParam1;
    int genericParam2;
    int genericParam3;
    int genericParam4;

};


#endif