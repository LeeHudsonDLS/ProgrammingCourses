//
// Created by jjc62351 on 22/10/2019.
//

#include "FiveASideTeam.h"

FiveASideTeam::FiveASideTeam(const std::string &p1, const std::string &p2, const std::string &p3, const std::string &p4,
                             const std::string &p5): Groupings<tuple5>(std::make_tuple(p1,p2,p3,p4,p5)) {}