#ifndef CHARGEMENTSEGMENT_H
#define CHARGEMENTSEGMENT_H
#include "expertchargement.h"
#include "../segment.h"

using namespace std;

class ChargementSegment : public ExpertChargement{


public:


    virtual Segment* chargement(string &objet) const{
        string contenu = objet;
        string type = "segment:";
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
            Couleurs::Couleur couleur = Couleurs::hexaToCouleur(valeurs[0]);
            if(couleur != Couleurs::nbCouleurs){
                return new Segment(couleur,Vecteur(x1,y1),Vecteur(x2,y2));
            }
        }

        return NULL;
    }


};

#endif // CHARGEMENTSEGMENT_H


/*
if(contenu.find(type.c_str()) == 0){
    string content[] = toParse.substring(type.length()).split(",");
    if(content.length == 5){
        string couleur = content[0].trim();
        int x1 =  Integer.parseInt(content[1].trim());
        int y1 =  Integer.parseInt(content[2].trim());
        int x2 =  Integer.parseInt(content[3].trim());
        int y2 =  Integer.parseInt(content[4].trim());
        return true;
    }
}
return false;
*/
