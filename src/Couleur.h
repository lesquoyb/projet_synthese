#ifndef COULEUR_H
#define COULEUR_H
#include <iostream>
#include <string>
using namespace std;

class Couleurs {

private:
    static const int nbCouleurs = 6;
    static const string correspondances[];
    static const string hexa[];

public:

    enum Couleur{black,white,yellow,red};

    static string couleurToString(const Couleur& couleur){
        return correspondances[couleur];
    }

    /**
     * @brief couleurToHexa
     * Permet d'obtenir le code hexadécimal correspondant à une couleur
     * @param couleur
     * @return le code hexadeciale sous la forme "#RRGGBB"
     */
    static string stringToHexa(const string& couleur){
        int i;
        for(i = 0 ; i < nbCouleurs ; i++){
            if(correspondances[i] == couleur){
                break;
            }
        }
        return "#"+hexa[i];
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
