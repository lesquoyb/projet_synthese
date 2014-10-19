#ifndef COULEUR_H
#define COULEUR_H
#include <iostream>
#include <string>
using namespace std;

class Couleurs {

private:
    static const int nbCouleurs = 4;
    static const string correspondances[];

public:

    enum Couleur{black,white,yellow,red};

    static string couleurToString(const Couleur& couleur){
        return correspondances[couleur];
    }

    static bool isCouleur(const string& coul) {
        for (int i = 0; i < nbCouleurs; i++){
            if (correspondances[i] == coul){
                return true;
            }
        }
        return false;
    }
};



#endif // COULEUR_H
