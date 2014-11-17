#include "vecteur.h"
#include "point.h"

Vecteur::Vecteur(double deplacementX, double deplacementY):
    _deplacementX(deplacementX),
    _deplacementY(deplacementY)
    {}

Vecteur::Vecteur(const Point &p1, const Point & p2):
    _deplacementX( p2.getX() - p1.getX()),
    _deplacementY( p2.getY() - p1.getY())
    {}

double Vecteur::getDeplacementX() const{
    return _deplacementX;
}

double Vecteur::getDeplacementY() const{
    return _deplacementY;
}


Vecteur operator* (double c, const Vecteur &v){
    return Vecteur(v.getDeplacementX()*c , v.getDeplacementY()*c);
}

std::ostream& operator<<(std::ostream &stream, const Vecteur&v){
    stream << "deltaX: " << v._deplacementX <<" deltaY: "<< v._deplacementY;
    return stream;
}

double Vecteur::norme()const{
    return sqrt( pow(_deplacementX,2) + pow(_deplacementY,2) );
}


double operator* (const Vecteur &v1,const Vecteur& v2){
    return v1._deplacementX*v2._deplacementX + v1._deplacementY*v2._deplacementY;
}


