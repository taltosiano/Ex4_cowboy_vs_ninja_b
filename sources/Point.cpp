#include <cmath>
#include <iostream>
#include <Point.hpp>

using namespace std;

namespace ariel{

Point::Point(double x, double y) : x(x), y(y) {}
Point::Point() : x(0), y(0) {}

double Point::distance(const Point& other) {
    double dx = this->getX() - other.getX();
    double dy = this->getY() - other.getY();
    return sqrt(dx*dx + dy*dy);
}

void Point::print(){
    cout << "(" << getX() << ", " << getY() << ")" << endl;
}

Point Point::moveTowards(const Point& source, const Point& dest, double distance){  
    return (*this);
}

double Point::getX() const{
    return this->x;
}
double Point::getY() const{
    return this->y;
}
}