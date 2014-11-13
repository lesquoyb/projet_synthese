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

class Point;
class Angle;

class FormeGeom{

protected:

    string _couleur;


public:

    FormeGeom();
    FormeGeom(const string & coul);


    virtual ~FormeGeom();
    virtual string serialisation()const = 0;
    virtual double aire()const = 0;
    virtual FormeGeom* rotation(const Point &p, const Angle& angle)const = 0;
    virtual FormeGeom* homothetie(const Point& p, const double scale)const = 0;
    virtual FormeGeom* translation(const Vecteur& v)const = 0;
    virtual void dessin(const Dessinable&)const = 0 ;

};

#endif // FORMEGEOM_H
