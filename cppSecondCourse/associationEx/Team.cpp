//
// Created by jjc62351 on 03/10/2019.
//

#include "Team.h"

League Team::league;

void operator>>(Team& l, Team& r){
    l.wins++;
    r.losses++;
}


Team::Team(std::string name): name(name), wins(0), losses(0) {
    league.addTeam(*this);
}

int Team::getWins() const {return wins;}
int Team::getLosses() const {return losses;}
void Team::printTable() {league.printTable();}

