#include <iostream>

#include "SpecialController.h"

int main() {

    SpecialController myController("testing");
    sprintf(myController.outString_,"Command");
    myController.specialPrint();
    myController.util.utilityMethod();

    return 0;
}