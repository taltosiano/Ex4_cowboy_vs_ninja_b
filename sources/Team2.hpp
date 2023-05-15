#ifndef TEAM2_HPP
#define TEAM2_HPP

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Point.hpp"
#include "Character.hpp"

namespace ariel{
class Team2{
private:
    Character* leader;
    vector<Character> members;

    public:
    Team2(Character* leader);
    ~Team2();
    void add(Character* member);
    void attack(Team2* enemy);
    int stillAlive();
    string print();


};
}
#endif