#ifndef CHARGEMENTTRIANGLE_H
#define CHARGEMENTTRIANGLE_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "expertchargement.h"
#include "../triangle.h"

using namespace std;

class ChargementTriangle : public ExpertChargement{


public:


    virtual Triangle* traitementSpecialise(string &objet) const{
        string contenu = objet;
        string type = "triangle:";
        if(contenu.find(type) == 0){
            contenu = contenu.substr(type.size()); // on enlève le type de la chaine
            vector<string> valeurs = split(contenu,',');
            for( int i = 0 ; i < valeurs.size() ; i++ ){
                valeurs[i] = trim(valeurs[i]);
            }
            double x1 = stod(valeurs[1].c_str());
            double y1 = stod(valeurs[2].c_str());
            double x2 = stod(valeurs[3].c_str());
            double y2 = stod(valeurs[4].c_str());
            double x3 = stod(valeurs[5].c_str());
            double y3 = stod(valeurs[6].c_str());
            Couleurs::Couleur couleur = Couleurs::hexaToCouleur(valeurs[0]);
            if(couleur != Couleurs::nbCouleurs){
                return new Triangle(couleur,Point(x1,y1),Point(x2,y2),Point(x3,y3));
            }
        }

        return NULL;
    }


};


#endif // CHARGEMENTTRIANGLE_H
