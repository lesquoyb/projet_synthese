#ifndef FORMEGEOM_H
#define FORMEGEOM_H

#include "point.h"
#include <iostream>
#include <string>
#include "vecteur.h"
#include <math.h>
#include "Couleur.h"
#include <sstream>
#include "objetgeom.h"
#include "dessinManager.h"

using namespace std;

class Vecteur;
class Angle;
class Groupe;

class FormeGeom : public ObjetGeom {

protected:


    Couleurs::Couleur _couleur;
    Groupe* _appartientA;


public:

    FormeGeom();
    FormeGeom(const Couleurs::Couleur &coul);

    // setter / getter
    inline Groupe* appartientA()const;
    inline void setAppartientA(Groupe* g);
    inline void setCouleur(const Couleurs::Couleur &c);
    inline Couleurs::Couleur getCouleur()const;


    //On précise le type de retour sans implémenter
    virtual FormeGeom* rotation(const Point &p, const Angle& angle)const = 0;
    virtual FormeGeom* homothetie(const Point &p, const double &scale)const = 0;
    virtual FormeGeom* translation(const Vecteur& v)const = 0;
    virtual FormeGeom* clone()const = 0;


    //Fonctions virtuelles pure spécifiques à une forme géométrique
    virtual double aire()const = 0;
    virtual void dessin(const Dessinable&)const = 0 ;

    //Fonctions spécifiques à une forme géométrique implémentables dans la classe mère
    void sauvegarder(const string nomDeFichier)const;
    static FormeGeom* chargement(const string &nomDeFichier);


    virtual ~FormeGeom(){}

};

//getter
inline Groupe* FormeGeom::appartientA()const{ return _appartientA; }
inline Couleurs::Couleur FormeGeom::getCouleur()const {return _couleur;}
//setter
inline void FormeGeom::setAppartientA(Groupe *g) {_appartientA = g;}
inline void FormeGeom::setCouleur(const Couleurs::Couleur &c) {_couleur = c;}


#endif // FORMEGEOM_H
