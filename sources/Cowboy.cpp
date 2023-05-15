#include <cmath>
#include <iostream>
#include <string>
#include "Cowboy.hpp"
#include "Character.hpp"

using namespace std;

namespace ariel{

Cowboy::Cowboy(string name, Point location)
    : Character(location, 110, name), numOfBoolets(6) {}

void Cowboy::shoot(Character* enemy){
    if(isAlive() && hasboolets()){
        enemy->hit(10);
        this->numOfBoolets -= 1;
    }
    else {
        cout << getName() << " can't shoot!" << endl;
    }
}

bool Cowboy::hasboolets(){
    if(numOfBoolets > 0){
        return true;
    }
    return false;
}
void Cowboy::reload(){
    this->numOfBoolets += 6;
}

int Cowboy::getNumOfBoolets(){
    return this->numOfBoolets;
}

string Cowboy::print(){
    return "Cowboy: " + getName() + " ( number of hit points: " + 
         to_string(getHitPoints()) + "), position: (" + to_string(getLocation().getX()) + 
             ", " + to_string(getLocation().getY()) + ")" + to_string(getNumOfBoolets()) + " bullets left";;

}


}