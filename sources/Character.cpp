#include "Character.hpp"

using namespace std;

namespace ariel{

    Character::Character(Point location, int hitPoint, string name)
    : location(location), hitPoint(hitPoint), name(name), freeMember(true), isLeader_(false) {}
    //copy constructor
    Character::Character(const Character& other): location(other.location), hitPoint(other.hitPoint), name(other.name){}
    // Copy assignment operator
    Character& Character::operator=(const Character& other)
    {
    if (this != &other) {
        location = other.location;
        hitPoint = other.hitPoint;
        name = other.name;
    }
    return *this;
    }
    //move constructor
    Character::Character(Character&& other) noexcept : location(std::move(other.location)), hitPoint(std::move(other.hitPoint)), name(std::move(other.name)){}
    // move assignment operator
    Character& Character::operator=(Character&& other) noexcept
    {
    if (this != &other) {
        hitPoint = std::move(other.hitPoint);
        name = std::move(other.name);
        location = std::move(other.location);
    }
    return *this;
    }

    bool Character::isAlive() const{
        if (this->getHitPoints() > 0)
            return true;
        return false;
    }

    void Character::addToTeam(){
         freeMember = false;
    }

    bool Character::isFreeMember(){
        return freeMember;
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

    string Character::getName() const{
        return this->name;
    }

    Point Character::getLocation(){
        return this->location;
    }

    void Character::setLocation(Point newLoc) {
        this->location = newLoc;
    }

    void Character::isLeader(){
         this->isLeader_ = true;
    }

    bool Character::isLeaderBul(){
        return isLeader_;
    }

    int Character::getHitPoints() const{
        return this->hitPoint;
    }
}