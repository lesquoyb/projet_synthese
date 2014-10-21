#include "point.h"



Point::Point(const string &c) : FormeGeom(c) {}

Point::Point(const Point &p):
_x(p._x),
_y(p._y)
{}

Point::Point(const string &c, double x, double y):
FormeGeom(c),
_x(x),
_y(y)
{}

void Point::rotation(const Point &p,const Angle &angle){
    double d1 = sqrt( pow(_x - p._x,2) + pow(_y - p._y,2));
    _x =  d1 * cos(angle.getDegree()) + _x;
    _y =  d1 * sin(angle.getDegree()) + _y;
}

void Point::homothetie(const Point &p, const double scale){
    double distX = (_x - p._x );
    double distY = (_y - p._y );
    _x = p._x + scale * distX;
    _y = p._y + scale * distY;
}

void Point::translation(const Vecteur &v){
    _x += v.getDeplacementX();
    _y += v.getDeplacementY();
}

double Point::aire() const{
    return 0;
}

void Point::dessin() const{
    //TODO
}

bool Point::operator==(const Point &p)const{
    return ( (_x == p._x) and (_y == p._y));
}

double Point::getX() const{
    return _x;
}

double Point::getY() const{
    return _y;
}

ostream& operator<<(ostream& stream,const Point& p ){
    stream << "x: " << p._x<< ",y: " << p._y;
    return stream;
}
