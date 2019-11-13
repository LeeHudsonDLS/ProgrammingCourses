#include <iostream>
#include <string>
#include "Time.h"
#include "Smart.h"

void f(Smart& ptr){
    ptr->hello();
    throw "problems";
}

int main() {

    //Stack
    Time t(3,30);

    try {
        //Create object on the stack pointing to object on heap
        Smart s(new Time(2,30));
        f(s);
    }catch (const char* e){
        std::cout << e << std::endl;
    }
}