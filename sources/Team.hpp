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
    vector<Character*> members;

    public:
    Team(Character* leader);
    Team();
    Team(const Team& other) = default;
    Team& operator=(const Team& other) = default;
    Team(Team&& other) = default;
    Team& operator=(Team&& other) = default;
    virtual ~Team();
    Character* getLeader() const;
    void setLeader(Character* lead);
    void add(Character* member);
    virtual void attack(Team* enemy);
    Character* getClosestEnemy(Team* enemy);
    vector<Character*> getMembers();
    int stillAlive();
    virtual void print();
    Character* getClosestAliveMember();   
};
}
#endif