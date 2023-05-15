#include <cmath>
#include <iostream>
#include <string>
#include "Point.hpp"
#include "Ninja.hpp"
#include "Character.hpp"

using namespace std;

namespace ariel {
    Ninja::Ninja(string name, Point location, int hitPoints, int speed)
        : Character(location, hitPoints, std::move(name)), speed(speed) {}
        
    void Ninja::move( Character* enemy){
        Point enemyLoc = enemy->getLocation();
        double distance = this->distance(enemy);
        double dx = (enemyLoc.getX() - getLocation().getX()) / distance;
        double dy = (enemyLoc.getY() - getLocation().getY()) / distance;
        Point myNewLoc(getLocation().getX() + this->speed * dx, getLocation().getY() + this->speed * dy);
        setLocation(myNewLoc);
    }
    void Ninja::slash( Character* enemy){
        if(isAlive() && distance(enemy) < 1000){
            enemy->hit(40);
        }
        else{
            cout << " Nothing is change !" << endl;      
        };
    }
    int Ninja::getSpeed(){
        return this->speed;
    }

    string Ninja::print(){
         return "Ninja: " + getName() + " ( number of hit points: " + to_string(getHitPoints()) 
         + "), position: (" + to_string(getLocation().getX()) + ", " + to_string(getLocation().getY()) + "), ";
    }
};
