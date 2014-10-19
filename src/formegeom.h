#ifndef FORMEGEOM_H
#define FORMEGEOM_H
#include <iostream>
#include <string>
using namespace std;

class FormeGeom{

private:

    string couleur;


public:
    FormeGeom(const string & coul);
    virtual double aire()const = 0;
    virtual ~FormeGeom();
    virtual void rotation(const Angle& angle) = 0;
    virtual void homothetie(const Point& p, const double scale) = 0;
    virtual void translation(const Vecteur& v) = 0;
    virtual void dessin() = 0 ;

};

#endif // FORMEGEOM_H
