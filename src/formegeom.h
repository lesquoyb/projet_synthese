#ifndef FORMEGEOM_H
#define FORMEGEOM_H

#include "point.h"
#include <iostream>
#include <string>
#include "vecteur.h"
#include <math.h>
#include "Couleur.h"
#include <sstream>

#include "dessinManager.h"

using namespace std;

class Vecteur;
class Angle;

class FormeGeom{

protected:

    Couleurs::Couleur _couleur;


public:

    FormeGeom();
    FormeGeom(const Couleurs::Couleur &coul);

    void sauvegarder(const string nomDeFichier)const;
    static FormeGeom* chargement(const string &nomDeFichier);

    virtual ~FormeGeom(){}

    virtual FormeGeom* getCoordEntiere()const = 0;
    virtual string toString()const = 0;
    virtual double aire()const = 0;
    virtual FormeGeom* rotation(const Vecteur &p, const Angle& angle)const = 0;
    virtual FormeGeom* homothetie(const Vecteur& p, const double scale)const = 0;
    virtual FormeGeom* translation(const Vecteur& v)const = 0;
    virtual FormeGeom* clone()const = 0;
    virtual void dessin(const Dessinable&)const = 0 ;

};

#endif // FORMEGEOM_H
