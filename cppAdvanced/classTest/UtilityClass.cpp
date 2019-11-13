//
// Created by jjc62351 on 23/10/2019.
//
//#include <iostream>
#include "UtilityClass.h"
#include "SpecialController.h"

UtilityClass::UtilityClass(int utilVal, SpecialController& ref):utilVal(utilVal),ref(ref) {
}

void UtilityClass::utilityMethod() {
    std::cout << ref.specialParam1 << std::endl;
    ref.writeToHardware2();
    std::cout << "utilityMethod()\n";
}