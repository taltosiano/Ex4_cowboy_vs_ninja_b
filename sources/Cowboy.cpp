#include "Cowboy.hpp"

using namespace std;

namespace ariel{

Cowboy::Cowboy(string name, Point location)
    : Character(location, 110, name), numOfBoolets(6) {}

void Cowboy::shoot(Character* enemy){
    if(this == enemy){
        throw std::runtime_error("no self harm!!");
    }
    if(!this->isAlive()){
        throw std::runtime_error("this Cowboy is dead!");
    }
     if(!enemy->isAlive()){
         throw std::runtime_error("this enemy is dead!");
    }
    if(hasboolets()){
        enemy->hit(10);
        this->numOfBoolets -= 1;
    }
}

bool Cowboy::hasboolets(){
    if(numOfBoolets > 0){
        return true;
    }
    return false;
}
void Cowboy::reload(){
    if(this->isAlive()){
        this->numOfBoolets = 6;
    }
    else{
    throw std::runtime_error("cannot reload dead cowboy\n");
};
}

int Cowboy::getNumOfBoolets(){
    return this->numOfBoolets;
}

string Cowboy::print(){
    if (!isAlive()) {
        return '(' + getName() + ')';
    } else {
    return "C: " + getName() + " ( number of hit points: " + 
         to_string(getHitPoints()) + "), position: (" + to_string(getLocation().getX()) + 
             ", " + to_string(getLocation().getY()) + ")" + to_string(getNumOfBoolets()) + " bullets left";;

};
}

}