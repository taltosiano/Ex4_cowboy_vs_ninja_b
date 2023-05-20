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

    public:
    Character(Point location, int hitPoint, std::string name);
    //Character() = default;
    Character& operator=(Character&&) noexcept;
    virtual ~Character(); //= default;
    bool isAlive() const;
    double distance(Character* other);
    void hit(int num);
    std::string getName() const;
    Point getLocation() const;
    void setLocation(Point newLoc);
    virtual std::string print() = 0;
    int getHitPoints() const;
    bool isFreeMember();
    void addToTeam();

    Character(const Character&);
    Character& operator=(const Character&); //==delete?
    Character(Character&&) noexcept;
};
}
#endif