#include "point.h"
#include "matricecarree2.h"
#include "vecteur.h"


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
    stream << "x: " << p.getX() << ",y: " << p.getY();
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

Point* Point::homothetie(const Point &p, double scale) const{
    return new Point(*p.translation(scale* Vecteur(p,*this)));
}

Point* Point::translation(const Vecteur &v)const{
    return new Point(v + _coord);
}

double Point::getDist(const Point &p)const{
    return Vecteur(*this,p).norme();
}


bool Point::operator==(const Point &p)const{
    return p._coord == _coord;
}
