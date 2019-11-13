//
// Created by jjc62351 on 23/10/2019.
//

#include "Controller.h"

Controller::Controller(std::string ipAddress):ipAddress(ipAddress) {

}

void Controller::writeToHardware() {
    std::cout << "Writing to hardware" << std::endl;
}


void Controller::writeToHardware2() {
    std::cout << "Writing to hardware2" << std::endl;
}