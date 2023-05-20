#ifndef POINT_HPP
#define POINT_HPP

#pragma once
#include <cmath>
#include <iostream>
#include <stdexcept>

namespace ariel {
class Point {
private:
    double x;
    double y;

public:
    Point();
    Point(double pointX, double pointY);
    double distance(const Point& point);
    void print();
    static Point moveTowards(Point source, Point dest, double distance);
    double getX() const;
    double getY() const;
};
}
#endif