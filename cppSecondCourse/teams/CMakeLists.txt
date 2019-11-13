cmake_minimum_required(VERSION 3.14)
project(teams)

set(CMAKE_CXX_STANDARD 14)

add_executable(teams main.cpp League.cpp League.h Team.cpp Team.h)