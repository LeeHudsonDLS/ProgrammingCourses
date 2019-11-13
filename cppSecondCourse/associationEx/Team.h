//
// Created by jjc62351 on 03/10/2019.
//

#ifndef ASSOCIATIONEX_TEAM_H
#define ASSOCIATIONEX_TEAM_H
#include <vector>
#include <string>
#include "League.h"

class League;
class Team {
public:
    friend void operator>>(Team& l, Team& r);
    Team(std::string name);
    int getWins() const;
    int getLosses() const;
    static void printTable() ;

private:
	static League league;
    std::string name;
    int wins,losses;
};


#endif //ASSOCIATIONEX_TEAM_H
