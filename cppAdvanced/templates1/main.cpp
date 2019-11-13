#include <iostream>
#include <string>

template <typename T>
T Max(T a, T b){
    if(a>b)
        return a;
    else
        return b;
}

int main() {
    std::cout << Max(5,8) << std::endl;
    std::cout << Max(5.1,8.8) << std::endl;
    std::cout << Max(std::string("Red"),std::string("Blue")) << std::endl;



}