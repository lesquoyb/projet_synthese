#ifndef COULEUR_H
#define COULEUR_H
#include <iostream>
#include <string>
using namespace std;
class Couleurs {
private:
    static const int nbCouleurs = 4;
    static const string correspondances[nbCouleurs];

public:

    enum class  Couleur{black,white,yellow,red};

    string couleurToString(const Couleur& couleur)const{
        return correspondances[couleur];
    }

    bool isCouleur(const string& coul) const {
        for (int i = 0; i < nbCouleurs; i++){
            if ()
        }
    }

}
Couleurs::correspondances[Couleurs::nbCouleurs] = {"black","white", "yellow","red"};


#endif // COULEUR_H
