//
// Created by jjc62351 on 03/10/2019.
//

#include "Smart.h"

Smart::Smart(Time *ptr):ptr(ptr) {}
Smart::~Smart(){delete ptr;}
Time* Smart::operator->() { return ptr;}