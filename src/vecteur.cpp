#include "vecteur.h"

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

