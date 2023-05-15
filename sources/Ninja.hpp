#ifndef NINJA_HPP
#define NINJA_HPP

#pragma once
#include <cmath>
#include <iostream>
#include <string>
#include "Character.hpp"

namespace ariel
{
class Ninja : public Character {
    private:
    int speed; 

    public:
    Ninja(string name, Point location, int hitPoint, int speed);
    void move( Character* enemy);
    void slash( Character* enemy);
    int getSpeed();
    string print() override;
};

}
#endif