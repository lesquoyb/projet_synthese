#include "point.h"




Point::Point(const Point &p):
_x(p._x),
_y(p._y)
{}

Point::Point(const string &c, double x, double y):
_x(x),
_y(y)
{}

void Point::translation(const Vecteur &v){
    _x += v.getDeplacementX();
    _y += v.getDeplacementY();
}


ostream& operator<<(ostream& stream,const Point& p ){
    stream << "x: " << p._x<< ",y: " << p._y;
    return stream;
}
