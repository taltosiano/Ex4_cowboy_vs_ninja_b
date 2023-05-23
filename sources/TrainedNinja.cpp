#include "TrainedNinja.hpp"

using namespace std;

namespace ariel{

    TrainedNinja::TrainedNinja(string name, Point location) : Ninja(name, location, 120, 12) {}
    TrainedNinja::TrainedNinja() : Ninja("default_name", Point(0,0), 150, 8){}

}