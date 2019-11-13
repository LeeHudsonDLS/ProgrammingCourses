//
// Created by jjc62351 on 03/10/2019.
//

#ifndef ASSOCIATIONEX_LEAGUE_H
#define ASSOCIATIONEX_LEAGUE_H

#include <iostream>
#include <vector>
#include <string>

#include "Team.h"

class Team;

class League {
public:
    League();
    void addTeam(const Team& team);
    void printTable() const;

private:
    std::vector<const Team*> teams;
};


#endif //ASSOCIATIONEX_LEAGUE_H
