#include "cercle.h"
#include "point.h"
#include "Tools.h"


Cercle* Cercle::rotation(const Point &p, const Angle &angle)const{
	return new Cercle(*this);
}

Cercle* Cercle::homothetie(const Point &p, const double scale)const{
    return new Cercle(_couleur,_centre,_rayon * scale);
   //TODO
}

Cercle* Cercle::translation(const Vecteur &v)const{
    return new Cercle(_couleur,*_centre.translation(v),_rayon);
}

void Cercle::dessin(const Dessinable &d) const{
    d.dessinerCercle(*this);
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


string Cercle::serialisation()const{
    ostringstream oss;
    oss << "cercle: " <<  Couleurs::stringToHexa(_couleur) << ", " <<  _centre.getX() << ", " <<  _centre.getY() << ", " <<  _rayon;
    return oss.str();
}

