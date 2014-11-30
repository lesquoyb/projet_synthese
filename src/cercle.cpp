#include "cercle.h"
#include "point.h"


Cercle* Cercle::rotation(const Point &p, const Angle &angle)const{
    return new Cercle(_couleur,*_centre.rotation(p,angle),_rayon);
}

Cercle* Cercle::homothetie(const Point &p, const double &scale)const{
    return new Cercle(_couleur,*_centre.homothetie(p,scale), abs(_rayon * scale));
}

Cercle* Cercle::translation(const Vecteur &v)const{
    Point* p = _centre.translation(v);
    Cercle* c = new Cercle(_couleur,*p,_rayon);
    delete p;
    return c;
}

void Cercle::dessin(const Dessinable &d) const{
    d.dessinerCercle(*this);
}

Cercle::Cercle(const Point &centre, double rayon):
FormeGeom(),
_centre(centre),
_rayon(abs(rayon))
{}

Cercle::Cercle(const Couleurs::Couleur &couleur,const Point &centre, double rayon):
FormeGeom(couleur),
_centre(centre),
_rayon(abs(rayon))
{}

double Cercle::aire() const{
    return _rayon*_rayon*(Angle::PI);
}


string Cercle::toString()const{
    ostringstream oss;
    oss << "cercle: " <<  _couleur << ", " <<  _centre.getX() << ", " <<  _centre.getY() << ", " <<  _rayon;
    return oss.str();
}





