#ifndef CHARGEMENTFACADE_H
#define CHARGEMENTFACADE_H
#include "chargementsegment.h"
#include "chargementcercle.h"
#include "chargementgroupe.h"
#include "chargementpolygone.h"
#include "chargementtriangle.h"
#include "facade.h"
#include "../tools.h"

/**
 * @brief The ChargementFacade class
 * Spécialisation de la façade pour s'occuper d'ExpertChargement.
 */
class ChargementFacade : public Facade<FormeGeom,string>{

private:

     void init(){
         _first = new ChargementCercle();
         _first->ajouterSuivant(new ChargementSegment());
         _first->ajouterSuivant(new ChargementTriangle());
         _first->ajouterSuivant(new ChargementPolygone());
         _first->ajouterSuivant(new ChargementGroupe());

     }


public:

    ChargementFacade(ifstream &file){
        _objet = lireFichier(file);
        init();
    }

    ChargementFacade(string contenu){
        _objet = contenu;
        init();
    }


};

#endif // CHARGEMENTFACADE_H
