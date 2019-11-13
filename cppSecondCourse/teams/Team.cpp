//
// Created by jjc62351 on 03/10/2019.
//

#include "Team.h"

League Team::league;

void operator>>(Team& l,Team& r){
    l.wins++;
    r.losses++;
}

Team::Team(std::string name): name(name), wins(0), losses(0) {
    league.addTeam(*this);
}

void Team::printTable() {
    league.diplay();
}
void Team::print() {
    std::cout << name << " , Wins:" << wins << ", Losses:" << losses << std::endl;
}