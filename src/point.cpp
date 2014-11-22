#include "point.h"
#include "matricecarree2.h"


/*
Vecteur::Vecteur(const Vecteur &p):
_x(p._x),
_y(p._y)
{}

Vecteur::Vecteur( double x, double y):
_x(x),
_y(y)
{}

Vecteur Vecteur::translation(const Vecteur &v)const{
    return Vecteur(_x + v.getX(), _y + v.getY());
}


ostream& operator<<(ostream& stream,const Vecteur& p ){
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
/*
Vecteur Vecteur::rotation(const Vecteur &p, const Angle &a) const{
    Vecteur rot(MatriceCarree2::getMatriceRotation(a) * Vecteur(p,*this));
    return  Vecteur(  p.getX() + rot.getX() , p.getY() + rot.getY() );
}

Vecteur Vecteur::homothetie(const Vecteur &p, double scale) const{
    return p.translation(scale* Vecteur(p,*this));
}
*/
