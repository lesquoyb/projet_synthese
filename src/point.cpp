#include "point.h"




Point::Point(const Point &p):
_x(p._x),
_y(p._y)
{}

Point::Point( double x, double y):
_x(x),
_y(y)
{}

Point Point::translation(const Vecteur &v)const{
    return Point(_x + v.getDeplacementX(), _y + v.getDeplacementY());
}


ostream& operator<<(ostream& stream,const Point& p ){
    stream << "x: " << p._x<< ",y: " << p._y;
    return stream;
}

/**
 * @brief Point::rotation
 * @param p le point à partir duquel il faut effectuer la rotation
 * @param a l'angle de la rotation
 * @return le point résultat
 * Permet de calculer le point issus de la rotation du point courrant par rapport à p et a
 */
Point Point::rotation(const Point &p, const Angle &a) const{
    //TODO:test
    double theta = a.getRadian();
    double x = cos(theta) * (_x - p._x) - sin(theta) * (_y - p._y) + p._x;
    double y = sin(theta) * (_x - p._x) + cos(theta) * (_y - p._y) + p._y;
    return Point(x, y);
}

Point Point::homothetie(const Point &p, double scale) const{
    //TODO: test
    double deltaX = _x - p._x;
    double deltaY = _y - p._y;
    return p.translation(Vecteur(deltaX*scale,deltaY*scale));
}
