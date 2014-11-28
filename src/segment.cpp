#include "segment.h"


Segment::Segment(const Couleurs::Couleur &couleur, const Point &p, const Point &p2):
FormeGeom(couleur),
_p1(p),
_p2(p2)
{}

Segment::Segment(const Point &p, const Point &p2):
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

Segment* Segment::rotation(const Point &p, const Angle &angle)const{
    return new Segment(_couleur,*_p1.rotation(p,angle),*_p2.rotation(p,angle));
}

Segment* Segment::homothetie(const Point &p, const double &scale)const{
    Point p1 = *_p1.homothetie(p,scale);
    Point p2 = *_p2.homothetie(p,scale);
    return new Segment(_couleur,p1,p2);
}

Segment* Segment::translation(const Vecteur &v)const{
    return new Segment(_couleur, *_p1.translation(v), *_p2.translation(v) );
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
