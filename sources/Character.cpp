#include <cmath>
#include <iostream>
#include <string>
#include "Point.hpp"
#include "Character.hpp"

using namespace std;

namespace ariel{

    Character::Character(Point location, int hitPoint, string name)
    : location(location), hitPoint(hitPoint), name(name) {}

    bool Character::isAlive(){
        if (this->getHitPoints() > 0)
            return true;
        return false;
    }

    double Character::distance(Character* other){
        double dx = this->getLocation().getX() - other->getLocation().getX();
        double dy = this->getLocation().getY() - other->getLocation().getY();
        return sqrt(dx*dx + dy*dy);
    }

    void Character::hit(int num) {
    if (num < 0) {
        throw invalid_argument("The hit number cannot be negative number");
     }
        this->hitPoint -= num;
    }

    string Character::getName() {
        return this->name;
    }

    Point Character::getLocation(){
        return this->location;
    }

    void Character::setLocation(Point newLoc) {
        this->location = newLoc;
    }

    string Character::print(){
       if (!isAlive()) {
        return '(' + name + ')';
    } else {
                // If the character is alive, print the number of hit points and position
        return "( number of hit points" + to_string(getHitPoints()) + "), position: (" + 
                        to_string(getLocation().getX()) + ", " + to_string(getLocation().getY()) + ")";
    }       
    }

    int Character::getHitPoints(){
        return this->hitPoint;
    }

}

