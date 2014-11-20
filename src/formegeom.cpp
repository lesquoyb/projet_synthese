#include "formegeom.h"
#include "Couleur.h"
#include "../exceptions/exceptioncouleurinexistante.h"

FormeGeom::FormeGeom():
_couleur(Couleurs::black)
{}


FormeGeom::FormeGeom(const Couleurs::Couleur &coul):
    _couleur(coul)
{}


void FormeGeom::sauvegarder(const string nomDeFichier)const{
    filebuf fb;
    fb.open (nomDeFichier,ios::out);
    ostream os(&fb);
    os << toString();
    fb.close();
}
