#include "vecteur.h"
#include "point.h"

Vecteur::Vecteur(double deplacementX, double deplacementY):
    _deplacementX(deplacementX),
    _deplacementY(deplacementY)
    {}

double Vecteur::getDeplacementX() const{
    return _deplacementX;
}

double Vecteur::getDeplacementY() const{
    return _deplacementY;
}



Vecteur operator* (const Vecteur &v, double c){
    return Vecteur(v.getDeplacementX()*c , v.getDeplacementY()*c);
}

Vecteur operator* (double c, const Vecteur &v){
    return Vecteur(v.getDeplacementX()*c , v.getDeplacementY()*c);
}

