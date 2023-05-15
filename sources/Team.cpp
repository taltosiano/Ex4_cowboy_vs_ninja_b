#include <iostream>
#include <vector>
#include <algorithm>
#include "Point.hpp"
#include "Character.hpp"
#include "Team.hpp"

namespace ariel{
        Team::Team(Character* leader){}
        void Team::add(Character *member){}
        void Team::attack(Team *enemy){}
        int Team::stillAlive(){return 0;}
        string Team::print(){return "";}
        Team::~Team(){}
}