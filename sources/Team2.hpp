#ifndef TEAM2_HPP
#define TEAM2_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include "Point.hpp"
#include "Team.hpp"
#include "Character.hpp"

namespace ariel{
class Team2 : public Team {

    public:
    Team2(Character* leader);
    Team2();
    void attack(Team* enemy) override;
    void print() override;
};
}
#endif