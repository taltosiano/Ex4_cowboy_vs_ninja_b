#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include "Point.hpp"

using namespace std;
namespace ariel {
class Character{
    private:
        Point location;
        int hitPoint;
        string name;

    public:
    Character(Point location, int hitPoint, string name);
    virtual ~Character() = default;
    virtual bool isAlive();
    virtual double distance(Character* other);
    virtual void hit(int num);
    virtual string getName();
    virtual Point getLocation();
    void setLocation(Point location);
    virtual string print();
    int getHitPoints();
};
}
#endif