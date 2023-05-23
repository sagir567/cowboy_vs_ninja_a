#include "Point.hpp"
#include <cmath>
#include <iostream>

using namespace std;
using namespace ariel;


Point::Point(double x, double y): x(x), y(y) {
//    if (x < 0 || y < 0) {
//        throw invalid_argument("Point coordinates must be ");
//    }
}
Point::Point(Point const &p):x(p.getX()),y(p.getY()){};


Point::~Point(){

}

double Point::distance(Point dest)
{
//    if (dest.getX()<0 || dest.getY()<0) {
//        throw invalid_argument("Point  must be positive");
//    }
    return sqrt(pow(getX() - dest.getX(), 2) + pow(getY() - dest.getY(), 2));
}


double Point::getX() const
{
    return x;
}

double Point::getY() const
{
    return y;
}

void Point::setX(double x)
{
    this->x = x;
}

void Point::setY(double y)
{
    this->y = y;
}


Point Point::moveTowards(Point source, Point dest, double maxDist) {
//    if (source.getX() < 0 || source.getY() < 0|| dest.getX()<0 || dest.getY()<0) {
//        throw invalid_argument(" coordinates must be positive");
//    }
    if (maxDist < 0) {
        throw std::invalid_argument("");
    }
    int dist = source.distance(dest);
    if (dist  < maxDist) {
        return Point(dest.getX(), dest.getY());
    }

    double dx = dest.getX() - source.getX();
    double dy = dest.getY() - source.getY();

    double ratio = maxDist / source.distance(dest);
    if (ratio >= 1) {
        ratio = 1;
    }

    double pos_x = source.getX() + ratio * dx;
    double pos_y = source.getY() + ratio * dy;

    Point p = Point(pos_x, pos_y);
//    p.print();
    return p;
}


void Point::print(){
    cout <<"(" << getX()<<","<<getY()<<")"<<endl;
}


