#ifndef FORMEGEOM_H
#define FORMEGEOM_H
#include <iostream>
#include <string>
#include "angle.h"
#include "vecteur.h"
#include <math.h>

using namespace std;

class Point;

class FormeGeom{

protected:

    string _couleur;


public:

    FormeGeom();
    FormeGeom(const string & coul);
    virtual ~FormeGeom();
    virtual double aire()const = 0;
    virtual FormeGeom* rotation(const Point &p, const Angle& angle)const = 0;
    virtual FormeGeom* homothetie(const Point& p, const double scale)const = 0;
    virtual FormeGeom* translation(const Vecteur& v)const = 0;
    virtual void dessin()const = 0 ;

};

#endif // FORMEGEOM_H
