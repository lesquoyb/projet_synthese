#include "cercle.h"
#include "point.h"
#include "Tools.h"


void Cercle::rotation(const Point &p, const Angle &angle){}

void Cercle::homothetie(const Point &p, const double scale){
    _rayon *= scale;
    _centre.homothetie(p,scale);
}

void Cercle::translation(const Vecteur &v){
    _centre.translation(v);
}

void Cercle::dessin() const{
    //TODO
}

Cercle::Cercle(const Point &centre, double rayon):
FormeGeom(),
_centre(centre),
_rayon(rayon)
{}

Cercle::Cercle(const string &couleur,const Point &centre, double rayon):
FormeGeom(couleur),
_centre(centre),
_rayon(rayon)
{}

double Cercle::aire() const{
    return _rayon*_rayon*PI;
}
