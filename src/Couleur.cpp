#include "Couleur.h"

const string Couleurs::correspondances[Couleurs::nbCouleurs] = {"black","white", "yellow","red","green","blue"};
const string Couleurs::hexa[Couleurs::nbCouleurs] = {"000000","ffffff","c5c251","ff0000","00ff00","0000FF"};


bool Couleurs::isCouleur(const string &coul) {
    for (int i = 0; i < nbCouleurs; i++){
        if (correspondances[i] == coul){
            return true;
        }
    }
    return false;
}



ostream& operator << (ostream& stream, const Couleurs::Couleur &c){
    stream << Couleurs::couleurToString(c);
    return stream;
}

/**
 * @brief couleurToHexa
 * Permet d'obtenir le code hexadécimal correspondant à une couleur
 * @param couleur
 * @return le code hexadeciale sous la forme "#RRGGBB"
 */
string Couleurs::couleurToHexa(const Couleur &couleur){
    return "#"+hexa[couleur];
}


/**
 * @brief Couleurs::hexaToCouleur
 * Attention si la couleur passée n'existe pas, on renvoi nbCouleur.
 * @param hexa
 * @return
 */
Couleurs::Couleur Couleurs::hexaToCouleur(const string & hexa){
    string donnee = hexa;
    if(hexa.find("#") == 0 ){
        donnee = hexa.substr(1);
    }
    int i = 0;
    for (; i < nbCouleurs ; i++){
        if(donnee == Couleurs::hexa[i]){
            break;
        }
    }
    return static_cast<Couleur>(i);
}


string Couleurs::couleurToString(const Couleur &couleur){
    return couleurToHexa(couleur);
}
