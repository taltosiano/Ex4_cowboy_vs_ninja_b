#ifndef SMARTTEAM_HPP
#define SMARTTEAM_HPP

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Point.hpp"
#include "Team.hpp"
#include "Character.hpp"

namespace ariel{
class SmartTeam : public Team{
    public:
    SmartTeam(Character* leader);
    SmartTeam();
    void attack(Team* enemy) override;
    void print() override;

};
}
#endif