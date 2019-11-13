//
// Created by jjc62351 on 23/10/2019.
//
#include "SpecialController.h"

SpecialController::SpecialController(std::string ipAddress):Controller(ipAddress),util(1,*this),specialParam1(66){

}

void SpecialController::specialPrint() {
    std::cout << "specialPrint()\n";
}