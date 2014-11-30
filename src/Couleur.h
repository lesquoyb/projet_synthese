#ifndef COULEUR_H
#define COULEUR_H

#include <iostream>
#include <string>
using namespace std;


/**
 * @brief The Couleurs class
 * Cette classe représente les différentes couleurs disponible dans l'application et contient les différentes méthodes utiles pour les manipuler.
 */
class Couleurs {


public:

    enum Couleur {black = 0 ,white,yellow,red,green,blue, nbCouleurs};

    /**
     * @brief couleurToString
     * @param couleur
     * @return un string représentant la couleur passée en paramètre
     */
    static string couleurToString(const Couleur& couleur);

    /**
     * @brief couleurToHexa
     * @param couleur
     * @return un string représentant la valeur hexadécimale de la couleur passée en paramètre sous la forme: "#RRGGBB".
     */
    static string couleurToHexa(const Couleur& couleur);

    /**
     * @brief hexaToCouleur
     * @param hexa
     * @return la couleur correspondant à la valeur hexadécimale passée en paramètre.
     */
    static Couleur hexaToCouleur(const string & hexa);

    /**
     * @brief isCouleur
     * @param coul
     * @return true si coul est une couleur correcte, false sinon.
     */
    static bool isCouleur(const string& coul);

    friend ostream& operator<< (ostream& , const Couleur &c);



private:

    static const string correspondances[];
    static const string hexa[];


};



#endif // COULEUR_H
