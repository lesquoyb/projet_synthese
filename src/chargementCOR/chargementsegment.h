#ifndef CHARGEMENTSEGMENT_H
#define CHARGEMENTSEGMENT_H
#include "expertchargement.h"
#include "../segment.h"

using namespace std;

/**
 * @brief The ChargementSegment class
 * L'expert en segment.
 */
class ChargementSegment : public ExpertChargement{


public:


    virtual Segment* traitementSpecialise(string &objet) const{
        string contenu = objet;
        string type = "segment:";
        if(contenu.find(type) == 0){
            contenu = contenu.substr(type.size()); // on enlève le type de la chaine
            vector<string> valeurs = split(contenu,',');
            for( size_t i = 0 ; i < valeurs.size() ; i++ ){
                valeurs[i] = trim(valeurs[i]);
            }
            double x1 = stod(valeurs[1].c_str());
            double y1 = stod(valeurs[2].c_str());
            double x2 = stod(valeurs[3].c_str());
            double y2 = stod(valeurs[4].c_str());
            Couleurs::Couleur couleur = Couleurs::hexaToCouleur(valeurs[0]);
            if(couleur != Couleurs::nbCouleurs){
                return new Segment(couleur,Point(x1,y1),Point(x2,y2));
            }
        }

        return NULL;
    }


};

#endif // CHARGEMENTSEGMENT_H

