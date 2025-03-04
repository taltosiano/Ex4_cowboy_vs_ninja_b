#include "Ninja.hpp"

using namespace std;

namespace ariel {
    Ninja::Ninja(string name, Point location, int hitPoints, int speed)
        : Character(location, hitPoints, std::move(name)), speed(speed) {}
        
    void Ninja::move( Character* enemy){
        Point new_location = Point::moveTowards(this->getLocation(), enemy->getLocation(), this->getSpeed());
        this->setLocation(new_location);
    }
    void Ninja::slash(Character* enemy){
        if(!(this->isAlive()) || !(enemy->isAlive()) || enemy == this){     
            throw std::runtime_error("Dead characters cannot attack and characters cannot attack a dead enemy + cannot self harm\n"); 
        }

        if(distance(enemy) < 1){
            enemy->hit(40);
        }
    }
    int Ninja::getSpeed(){
        return this->speed;
    }

    string Ninja::print(){
        if (!isAlive()) {
        return '(' + getName() + ')';
    } else {
         return "N: " + getName() + " ( number of hit points: " + to_string(getHitPoints()) 
         + "), position: (" + to_string(getLocation().getX()) + ", " + to_string(getLocation().getY()) + "), ";
    };
    }
}
