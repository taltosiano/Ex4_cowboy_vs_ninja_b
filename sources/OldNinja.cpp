#include "OldNinja.hpp"

using namespace std;

namespace ariel{

    OldNinja::OldNinja(string name, Point location) : Ninja(name, location, 150, 8) {}
    OldNinja::OldNinja() : Ninja("default_name", Point(0,0), 150, 8){}


}