#include <math.h>
#include <iostream>
#include "Point.hpp"

using namespace std;

namespace ariel{

    Point::Point(double x, double y):_x(x), _y(y){}
    Point::Point(){
        _x = 0;
        _y = 0;
    }
    Point::Point(const Point &other){
        _x = other._x;
        _y = other._y;
    }


    double Point::distance(Point p){
        double dis_x = p.getX() - this->_x;
        double dis_y = p.getY() - this->_y;
        double ans = sqrt(pow(dis_x,2)+pow(dis_y,2));
        return ans; 
    }
    void Point::moveTowards(Point src, Point dst, double dis){

    }

    void Point::setX(Point other){
        _x = other.getX();
    }

    void Point::setX(double other){
        _x = other;
    }

    void Point::setY(Point other){
        _y = other.getY();
    }

    void Point::setY(double other){
        _y = other;
    }

    bool Point::operator==(const Point& other) const{
        return (_x == other._x && _y == other._y);
    }

    ostream &operator<<(ostream &out, const Point &other)
    {
        Point res = other;
        out << to_string(res.getX()) << "/" << to_string(res.getY());
        return out;
    }
}