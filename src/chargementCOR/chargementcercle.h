#ifndef CHARGEMENTCERCLE_H
#define CHARGEMENTCERCLE_H
#include "expertchargement.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "../cercle.h"

using namespace std;

class ChargementCercle : public ExpertChargement{


public:


    virtual Cercle* traitementSpecialise(string &objet) const{
        string contenu = objet;
        string type = "cercle:";
        if(contenu.find(type) == 0){
            contenu = contenu.substr(type.size()); // on enlève le type de la chaine
            vector<string> valeurs = split(contenu,',');
            for( int i = 0 ; i < valeurs.size() ; i++ ){
                valeurs[i] = trim(valeurs[i]);
            }
            double x1 = stod(valeurs[1].c_str());
            double y1 = stod(valeurs[2].c_str());
            double rayon = stod(valeurs[3].c_str());
            Couleurs::Couleur couleur = Couleurs::hexaToCouleur(valeurs[0]);
            if(couleur != Couleurs::nbCouleurs){
                return new Cercle(couleur,Point(x1,y1),rayon);
            }
        }
        return NULL;
    }


};
#endif // CHARGEMENTCERCLE_H
