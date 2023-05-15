#ifndef TEAM_HPP
#define TEAM_HPP

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Point.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"

using namespace std;

namespace ariel {
class Team{
    private:
    Character* leader;
    vector<Character> members;

    public:
    Team(Character* leader);
    ~Team();
    void add(Character* member);
    void attack(Team* enemy);
    int stillAlive();
    string print();
};
}

#endif