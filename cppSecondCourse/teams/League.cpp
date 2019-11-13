//
// Created by jjc62351 on 03/10/2019.
//

#include "League.h"

void League::addTeam(Team& t) {
    teams.push_back(&t);
}

void League::diplay() {
    for(auto i : teams){
        i->print();
    }
}