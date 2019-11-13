//
// Created by jjc62351 on 03/10/2019.
//

#ifndef TEAMS_LEAGUE_H
#define TEAMS_LEAGUE_H
#import <vector>
#import "Team.h"
#import <string>
class Team;
class League {
public:
    void addTeam(Team& t);
    void diplay();
private:
    std::vector<Team*> teams;
};


#endif //TEAMS_LEAGUE_H
