#include "cercle.h"
#include "point.h"
#include "Tools.h"


Cercle* Cercle::getCoordEntiere()const{
    return new Cercle(_centre.getCoordEntieres(),_rayon);
}

Cercle* Cercle::rotation(const Point &p, const Angle &angle)const{
    return new Cercle(_couleur,_centre.rotation(p,angle),_rayon);
}

Cercle* Cercle::homothetie(const Point &p, const double scale)const{
    return new Cercle(_couleur,_centre.homothetie(p,scale), _rayon * scale);
}

Cercle* Cercle::translation(const Vecteur &v)const{
    return new Cercle(_couleur,_centre.translation(v),_rayon);
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
    return _rayon*_rayon*(Angle::PI);
}


string Cercle::toString()const{
    ostringstream oss;
    oss << "cercle: " <<  Couleurs::stringToHexa(_couleur) << ", " <<  _centre.getX() << ", " <<  _centre.getY() << ", " <<  _rayon;
    return oss.str();
}


bool operator==(const Cercle &c,const Cercle &c2){
    return (c._couleur == c2._couleur) && (c._centre == c2._centre) && (c._rayon == c2._rayon);
}

ostream& operator<<(ostream & stream, const Cercle &c){
    stream << c.toString();
    return stream;
}





