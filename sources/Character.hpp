#ifndef CHARACTER_HPP
#define CHARACTER_HPP

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
        std::string name;
        bool freeMember;
        bool isLeader_;

    public:
    Character(Point location, int hitPoint, string name);
    Character& operator=(Character&&) noexcept;
    virtual ~Character() = default;
    bool isAlive() const;
    double distance(Character* other);
    void hit(int num);
    std::string getName() const;
    Point getLocation();
    void setLocation(Point newLoc);
    virtual string print() = 0;
    int getHitPoints() const;
    bool isFreeMember();
    void addToTeam();
    void isLeader();
    bool isLeaderBul();

    Character(const Character& other);  // Copy constructor
    Character& operator=(const Character&); 
    Character(Character&& other) noexcept;  // Move constructor
};
}
#endif