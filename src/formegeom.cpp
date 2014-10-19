#include "formegeom.h"
#include "Couleur.h"
#include "../exceptions/exceptioncouleurinexistante.h"

FormeGeom::FormeGeom(const string &coul){
    if(Couleurs::isCouleur(coul)){
        _couleur = coul;
    }
    else{
        throw ExceptionCouleurInexistante(coul);
    }
}

FormeGeom::~FormeGeom(){}
