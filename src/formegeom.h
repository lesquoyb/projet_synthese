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

private:

    string _couleur;


public:

    FormeGeom(const string & coul);
    virtual double aire()const = 0;
    virtual ~FormeGeom();
    virtual void rotation(const Point &p, const Angle& angle) = 0;
    virtual void homothetie(const Point& p, const double scale) = 0;
    virtual void translation(const Vecteur& v) = 0;
    virtual void dessin()const = 0 ;

};

#endif // FORMEGEOM_H
