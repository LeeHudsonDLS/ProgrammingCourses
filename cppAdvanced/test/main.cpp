#include <iostream>

class C {
public:
    C(int val):val(val){};
    void printSomething(){
        std::cout << "C class out\n" << std::endl;
    }
private:
    int val;
};


class A {
public:
    A(int superVal):superVal(superVal){};
private:
    int superVal;
};

class B : public A {
public:
    B(int baseVal):A(baseVal),baseVal(baseVal),cClass(0){};
    std::string printBase(){
        char buffer[] = "Testing\n";
        return buffer;
    };
    C cClass;
private:
    int baseVal;

};


int main() {

B test(5);
test.cClass.printSomething();
std::cout << test.printBase() << std::endl;

}