#ifndef SMARTTEAM_HPP
#define SMARTTEAM_HPP

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Point.hpp"
#include "Character.hpp"

namespace ariel{
class SmartTeam{
private:
    Character* leader;
    vector<Character> members;

    public:
    SmartTeam(Character* leader);
    ~SmartTeam();
    void add(Character* member);
    void attack(SmartTeam* enemy);
    int stillAlive();
    string print();

};
}
#endif