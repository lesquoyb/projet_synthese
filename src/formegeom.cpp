#include "formegeom.h"
#include "Couleur.h"
#include "../exceptions/exceptioncouleurinexistante.h"

FormeGeom::FormeGeom():
_couleur("black")
{}

FormeGeom::FormeGeom(const string &coul = "black"){

    if(Couleurs::isCouleur(coul)){
        _couleur = coul;
    }
    else{
        throw ExceptionCouleurInexistante(coul);
    }
}

FormeGeom::~FormeGeom(){}


void FormeGeom::sauvegarder(const string nomDeFichier)const{
    filebuf fb;
    fb.open (nomDeFichier,ios::out);
    ostream os(&fb);
    os << toString();
    fb.close();
}
