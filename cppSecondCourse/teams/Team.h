//
// Created by jjc62351 on 03/10/2019.
//

#ifndef TEAMS_TEAM_H
#define TEAMS_TEAM_H

#import <string>
#import <iostream>
#import "League.h"

class League;

class Team {

public:
    Team(std::string name);
    friend void operator>>( Team& l,  Team& r);
    void print();
    static void printTable();

private:
    static League league;
    std::string name;
    int wins;
    int losses;

};


#endif //TEAMS_TEAM_H
