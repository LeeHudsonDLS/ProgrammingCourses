//
// Created by jjc62351 on 22/10/2019.
#include <iostream>
#include <vector>
#include <tuple>
#include <utility>
#include <sstream>
#include <memory>
#include <stdexcept>
#ifndef INTERFACESANDABSTRACTCLASSESEX_GROUPINGS_H
#define INTERFACESANDABSTRACTCLASSESEX_GROUPINGS_H

typedef std::pair<std::string,std::string> tuple2;
typedef std::tuple<std::string,std::string,std::string,std::string,std::string> tuple5;

template <typename T>
class Groupings {
public:
    Groupings(T list);
    virtual std::string info()=0;
    T getList();
    void setList(T);

private:
    T list;
};


#endif //INTERFACESANDABSTRACTCLASSESEX_GROUPINGS_H
