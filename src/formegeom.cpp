#include "formegeom.h"
#include "Couleur.h"
#include "chargementCOR/chargementfacade.h"

FormeGeom::FormeGeom():
_couleur(Couleurs::Couleur::black),
_appartientA(NULL)
{}


FormeGeom::FormeGeom(const Couleurs::Couleur &coul):
    _couleur(coul),
    _appartientA(NULL)
{}


void FormeGeom::sauvegarder(const string nomDeFichier)const{
    filebuf fb;
    fb.open (nomDeFichier,ios::out);
    ostream os(&fb);
    os << toString();
    fb.close();
}



FormeGeom* FormeGeom::chargement(const string &nomDeFichier){
    ifstream is;
    is.open(nomDeFichier,ios_base::in);
    return ChargementFacade(is).run();
}
