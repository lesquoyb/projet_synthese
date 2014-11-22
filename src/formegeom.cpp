#include "formegeom.h"
#include "Couleur.h"
#include "../exceptions/exceptioncouleurinexistante.h"
#include "chargementCOR/chargementfacade.h"

FormeGeom::FormeGeom():
_couleur(Couleurs::Couleur::black)
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



FormeGeom* FormeGeom::chargement(const string &nomDeFichier){
    ifstream is;
    is.open(nomDeFichier,ios_base::in);
    return chargementFacade().run(is);
}
