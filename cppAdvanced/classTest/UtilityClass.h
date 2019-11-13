//
// Created by jjc62351 on 23/10/2019.
//

#ifndef utilclass_H
#define utilclass_H
class SpecialController;

class UtilityClass {
public:
    UtilityClass(int utilVal,SpecialController& ref);
    void utilityMethod();
private:
    int utilVal;
    SpecialController& ref;

};

#endif

