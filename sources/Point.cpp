#include "Point.hpp"
#include <cmath>
#include <iostream>

using namespace std;
using namespace ariel;


Point::Point(double x, double y): x(x), y(y) {
    if (x < 0 || y < 0) {
        throw invalid_argument("Point coordinates must be positive");
    }
}
Point::Point(Point const &p):x(p.getX()),y(p.getY()){};


Point::~Point(){

}

double Point::distance(Point other)
{
    return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));
}

double Point::getX() const
{
    return this->x;
}

double Point::getY() const
{
    return this->y;
}

void Point::setX(double x)
{
    this->x = x;
}

void Point::setY(double y)
{
    this->y = y;
}

  Point Point::moveTowards(Point source, Point dest, double maxDist)
{
    int dist;
    if((dist=source.distance(dest)) < maxDist){
        return Point (dest.getX(), dest.getY());
    }
    double dx = dest.getX() - source.getX();
    double dy = dest.getY() - source.getY();
    dx/=dx*maxDist;
    dy/=dy*maxDist;

    return Point(source.getX()+dx, source.getY()+dy);
}

void Point::print(){
    cout <<"(" << getX()<<","<<getY()<<")"<<endl;
}


