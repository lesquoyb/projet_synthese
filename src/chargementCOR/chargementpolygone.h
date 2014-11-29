#ifndef CHARGEMENTPOLYGONE_H
#define CHARGEMENTPOLYGONE_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "expertchargement.h"
#include "../polygone.h"

using namespace std;

class ChargementPolygone : public ExpertChargement{


public:


    virtual Polygone* traitementSpecialise(string &objet) const{
        string contenu = objet;
        string type = "polygone:";
        if(contenu.find(type) == 0){
            contenu = contenu.substr(type.size()); // on enlève le type de la chaine
            vector<string> valeurs = split(contenu,',');
            for( size_t i = 0 ; i < valeurs.size() ; i++ ){
                valeurs[i] = trim(valeurs[i]);
            }

            if ( (valeurs.size() > 7 ) && ( ( valeurs.size() % 2) == 1 ) ){
                Couleurs::Couleur couleur = Couleurs::hexaToCouleur(valeurs[0]);

                double x1 = stod(valeurs[1].c_str());
                double y1 = stod(valeurs[2].c_str());
                double x2 = stod(valeurs[3].c_str());
                double y2 = stod(valeurs[4].c_str());
                double x3 = stod(valeurs[5].c_str());
                double y3 = stod(valeurs[6].c_str());
                Polygone* p = new Polygone(couleur,Point(x1,y1),Point(x2,y2),Point(x3,y3));
                for (size_t i = 7 ; i < valeurs.size() ; i+=2){
                    p->ajouterPoint(Point(stod(valeurs[i]),stod(valeurs[i+1])));
                }
                if(couleur != Couleurs::nbCouleurs){
                    return p;
                }
            }
        }

        return NULL;
    }


};
#endif // CHARGEMENTPOLYGONE_H
