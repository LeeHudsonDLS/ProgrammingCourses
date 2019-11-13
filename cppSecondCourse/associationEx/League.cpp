//
// Created by jjc62351 on 03/10/2019.
//

#include "League.h"

League::League() {}

void League::addTeam(const Team& team) {
    teams.push_back(&team);
}

void League::printTable() const {

    //for(auto i=teams.begin(); i != teams.end(); ++i){
        //std::cout << "Wins: " << i->printTable() << " Losses: " << *i->getLosses() << std::endl;
   //}
	for(const auto* pTeam : teams)
	{
	    std::cout << "Wins: " << pTeam->getWins() << " Losses: " << pTeam->getLosses() << std::endl;

	}
}