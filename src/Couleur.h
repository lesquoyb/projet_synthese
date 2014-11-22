#ifndef COULEUR_H
#define COULEUR_H

#include <iostream>
#include <string>
using namespace std;



class Couleurs {


public:

    enum Couleur {black = 0 ,white,yellow,red,green,blue, nbCouleurs};

    static string couleurToString(const Couleur& couleur);

    static string couleurToHexa(const Couleur& couleur);

    static Couleur hexaToCouleur(const string & hexa);

    static bool isCouleur(const string& coul);

    friend ostream& operator<< (ostream& , const Couleur &c);



private:

    static const string correspondances[];
    static const string hexa[];


};



#endif // COULEUR_H
