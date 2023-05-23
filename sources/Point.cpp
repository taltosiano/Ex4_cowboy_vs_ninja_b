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

Point Point::moveTowards(Point source, Point dest, double distance){  
    if(distance < 0){
        throw invalid_argument("distance argument must be non-negative");
    }
    double srcToDes = source.distance(dest);
    if (distance >= srcToDes) {
        return dest;
    }

    double dx = dest.x - source.x;
    double dy = dest.y - source.y;

    double moveX = dx / srcToDes * distance;
    double moveY = dy / srcToDes * distance;
    return Point(source.x + moveX, source.y + moveY);
}

double Point::getX() const{
    return this->x;
}
double Point::getY() const{
    return this->y;
}
}