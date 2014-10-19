#include "point.h"



Point::Point(const string &c) : FormeGeom(c) {}

Point::Point(double x, double y, const string &c):
FormeGeom(c),
_x(x),
_y(y)
{}

void Point::rotation(const Point &p,const Angle &angle){
    double d1 = sqrt( pow(_x - p._x,2) + pow(_y - p._y,2));
    _x =  d1 * cos(angle.getRadian()) + _x;
    _y =  d1 * sin(angle.getRadian()) + _y;
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

void Point::dessin(){
    //TODO
}
