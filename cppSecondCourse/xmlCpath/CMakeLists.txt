cmake_minimum_required(VERSION 3.14)
project(xmlCpath)

set(CMAKE_CXX_STANDARD 14)
include_directories(/usr/include/libxml2)

add_executable(xmlCpath main.cpp Sequencer.cpp Sequencer.h)

target_link_libraries(xmlCpath "/usr/lib64/libxml2.so.2")