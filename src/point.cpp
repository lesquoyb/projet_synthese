#include "point.h"




Point::Point(const Point &p):
_x(p._x),
_y(p._y)
{}

Point::Point( double x, double y):
_x(x),
_y(y)
{}

Point* Point::translation(const Vecteur &v)const{
    return new Point(_x + v.getDeplacementX(), _y + v.getDeplacementY());
}


ostream& operator<<(ostream& stream,const Point& p ){
    stream << "x: " << p._x<< ",y: " << p._y;
    return stream;
}

Point* Point::rotation(const Point &p, const Angle &a) const{
    //TODO
    return new Point(*this);
}
Point* Point::homothetie(const Point &p, double scale) const{
    //TODO
    return new Point(*this);
}
