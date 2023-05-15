#ifndef COWBOY_HPP
#define COWBOY_HPP

#pragma once
#include <cmath>
#include <iostream>
#include <string>
#include "Character.hpp"

namespace ariel {
class Cowboy : public Character {
    private:
    int numOfBoolets;

    public:
    Cowboy(string name,  Point location);
    void shoot(Character* enemy);
    bool hasboolets();
    void reload();
    int getNumOfBoolets();
    string print() override;

};
}
#endif