#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <string>

 using namespace std;

namespace ariel{

class Point{

private:
    double x;
    double y;

public:
    Point(double x=0, double y=0);
    double distance(Point other);
    double getX()const; 
    double getY()const; 
    Point moveTowards(Point source,Point dest, double dist);
    void setX(double x);
    void setY(double y);
    void print();
    ~Point();

};
}

#endif