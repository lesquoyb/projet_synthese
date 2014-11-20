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

    enum Couleur{black,white,yellow,red,green,blue};

    static string couleurToString(const Couleur& couleur);

    static string couleurToHexa(const Couleur& couleur);

    static bool isCouleur(const string& coul);

    friend ostream& operator<< (ostream& , const Couleur &c);
};



#endif // COULEUR_H
