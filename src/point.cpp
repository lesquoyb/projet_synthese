#include "point.h"
#include "matricecarree2.h"
#include "vecteur.h"
#include <sstream>


Point::Point(const Vecteur &v):
_coord(v)
{}

Point::Point( double x, double y):
_coord(Vecteur(x,y))
{}

Point::Point(const Point &p):
    _coord(p._coord)
{}



ostream& operator<<(ostream& stream,const Point& p ){
    stream << p.toString();
    return stream;
}

/**
 * @brief Point::rotation
 * @param p le point à partir duquel il faut effectuer la rotation
 * @param a l'angle de la rotation
 * @return le point résultat
 * Permet de calculer le point issus de la rotation du point courrant par rapport à p et a
 */
Point* Point::rotation(const Point &p, const Angle &a) const{
    Vecteur rot(MatriceCarree2::getMatriceRotation(a) * Vecteur(p,*this));
    return  new Point(  p._coord + rot );
}

Point* Point::homothetie(const Point &p, const double &scale) const{
    return  p.translation(scale* Vecteur(p,*this));
}

Point* Point::translation(const Vecteur &v)const{
    return new Point(v + _coord);
}

string Point::toString() const{
    std::ostringstream oss;
    oss << _coord.getX() << ", " << _coord.getY();
    return oss.str();
}

Point *Point::clone() const{
    return new Point(*this);
}

double Point::getDist(const Point &p)const{
    return Vecteur(*this,p).norme();
}

