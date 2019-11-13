//
// Created by jjc62351 on 23/10/2019.
//

#ifndef specclass_H
#define specclass_H

#include <string>
#include <iostream>

#include "Controller.h"
#include "UtilityClass.h"


class SpecialController: public Controller {
public:
    SpecialController(std::string ipAddress);

    void specialPrint();
    int specialParam1;
    int specialParam2;
    int specialParam3;
    int specialParam4;
    UtilityClass util;
};

#endif
