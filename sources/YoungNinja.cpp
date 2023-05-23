#include "YoungNinja.hpp"

using namespace std;

namespace ariel{

    YoungNinja::YoungNinja(string name, Point location) : Ninja(name, location, 100, 14) {}
    YoungNinja::YoungNinja() : Ninja("default_name", Point(0,0), 150, 8){}

}