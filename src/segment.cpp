#include "segment.h"


Segment::Segment(const Couleurs::Couleur &couleur, const Vecteur &p, const Vecteur &p2):
FormeGeom(couleur),
_p1(p),
_p2(p2)
{}

Segment::Segment( const Vecteur &p, const Vecteur &p2):
FormeGeom(),
_p1(p),
_p2(p2)
{}


bool operator==(const Segment&s, const Segment &s2){
    return (s._p1 == s2._p1) && (s._p2  == s2._p2) && (s._couleur == s2._couleur);
}

Segment* Segment::getCoordEntiere()const{
    return new Segment(this->_couleur, this->_p1.getCoordEntieres(),this->_p2.getCoordEntieres());
}

ostream& operator<<(ostream & stream, const Segment&s){
    stream << "couleur: " << s._couleur <<" p1: " << s._p1 << " p2: " << s._p2;
    return stream;
}

Segment* Segment::rotation(const Vecteur &p, const Angle &angle)const{
    return new Segment(_couleur,_p1.rotation(p,angle),_p2.rotation(p,angle));
}

Segment* Segment::homothetie(const Vecteur &p, const double scale)const{
    Vecteur p1 = _p1.homothetie(p,scale);
    Vecteur p2 = _p2.homothetie(p,scale);
    return new Segment(_couleur,p1,p2);
}

Segment* Segment::translation(const Vecteur &v)const{
    return new Segment(_couleur, _p1 + v, _p2 + v );
}

double Segment::aire() const{
    return 0;
}

void Segment::dessin(const Dessinable &d) const{
    d.dessinerSegment(*this);
}

string Segment::toString()const {
    ostringstream ser;
    ser << "segment: "<< _couleur << ", ";
    ser << _p1.getX() <<", " << _p1.getY() << ", " << _p2.getX() << ", " << _p2.getY();
    return ser.str();
}
