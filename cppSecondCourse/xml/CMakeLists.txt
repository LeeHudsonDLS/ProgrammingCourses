cmake_minimum_required(VERSION 3.14)
project(xml)

set(CMAKE_CXX_STANDARD 14)
include_directories(/usr/include/libxml2)

add_executable(xml main.cpp)

target_link_libraries(xml "/usr/lib64/libxml2.so.2")