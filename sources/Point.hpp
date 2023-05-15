#ifndef POINT_HPP
#define POINT_HPP

#pragma once
#include <cmath>
#include <iostream>

namespace ariel {
class Point {
private:
    double x;
    double y;

public:
    Point();
    Point(double x, double y);
    double distance(const Point& p);
    void print();
    Point moveTowards(const Point& source, const Point& dest, double distance);
    double getX() const;
    double getY() const;
};
}
#endif