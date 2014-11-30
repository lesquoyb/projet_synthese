#include "cercle.h"
#include "point.h"


Cercle* Cercle::rotation(const Point &p, const Angle &angle)const{
    Point* c = _centre.rotation(p,angle);
    Cercle* ret = new Cercle(_couleur,*c,_rayon);
    delete c;
    return ret;
}

Cercle* Cercle::homothetie(const Point &p, const double &scale)const{
    Point* c = _centre.homothetie(p,scale);
    Cercle* ret = new Cercle(_couleur,*c, abs(_rayon * scale));
    delete c;
    return ret;
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
    oss << "cercle: " <<  _couleur << ", " <<  _centre.toString() << ", " <<  _rayon;
    return oss.str();
}





