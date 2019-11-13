//
// Created by jjc62351 on 03/10/2019.
//

#ifndef HEAP_SMART_H
#define HEAP_SMART_H

#include "Time.h"

class Smart {
public:
    Smart(Time* ptr);
    ~Smart();
    // This needs to be overloaded to access heap object
    Time* operator->();
private:
    Time* ptr;

};


#endif //HEAP_SMART_H
