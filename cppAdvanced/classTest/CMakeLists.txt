cmake_minimum_required(VERSION 3.14)
project(classTest)

set(CMAKE_CXX_STANDARD 14)

add_executable(classTest main.cpp Controller.cpp SpecialController.cpp UtilityClass.cpp)