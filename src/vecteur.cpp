#include <sstream>
#include "point.h"
#include "vecteur.h"
#include "matricecarree2.h"
#include "point.h"

using namespace std;


Vecteur::Vecteur(const double &x, const double &y):
    _x(x),
    _y(y)
    {}
Vecteur::Vecteur(const Point &p1,const Point &p2):
_x( p2.getX() - p1.getX()),
_y( p2.getY() - p1.getY())
{}



Vecteur::Vecteur(const Vecteur &v1, const Vecteur & v2):
    _x( v2.getX() - v1.getX()),
    _y( v2.getY() - v1.getY())
    {}

double Vecteur::getX() const{
    return _x;
}

double Vecteur::getY() const{
    return _y;
}

std::ostream& operator<<(std::ostream &stream, const Vecteur&v){
    stream << (string) v;
    return stream;
}

double Vecteur::norme()const{
    return sqrt( pow(_x,2) + pow(_y,2) );
}

Vecteur::operator string()const{
    ostringstream oss;
    oss << "( " << _x << ", " << _y << ") ";
    return oss.str();
}


/**
 * @brief Point::rotation
 * @param p le point à partir duquel il faut effectuer la rotation
 * @param a l'angle de la rotation
 * @return le point résultat
 * Permet de calculer le point issus de la rotation du point courrant par rapport à p et a
 */
Vecteur Vecteur::rotation(const Vecteur &p, const Angle &a) const{
    Vecteur rot(MatriceCarree2::getMatriceRotation(a) * Vecteur(p,*this));
    return  Vecteur(  p.getX() + rot.getX() , p.getY() + rot.getY() );
}

Vecteur Vecteur::homothetie(const Vecteur &p, double scale) const{
    return p + (scale* Vecteur(p,*this));
}
