cmake_minimum_required(VERSION 3.14)
project(composition)

set(CMAKE_CXX_STANDARD 14)

add_executable(composition main.cpp Point.cpp Point.h Rectangle.cpp Rectangle.h)