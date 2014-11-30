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


Segment* Segment::rotation(const Point &p, const Angle &angle)const{
    Point* p1 = _p1.rotation(p,angle);
    Point* p2 = _p2.rotation(p,angle);
    Point temp1 = *p1;
    Point temp2 = *p2;
    delete p1;
    delete p2;
    return new Segment(_couleur,temp1,temp2);
}

Segment* Segment::homothetie(const Point &p, const double &scale)const{
    Point* p1 = _p1.homothetie(p,scale);
    Point* p2 = _p2.homothetie(p,scale);
    Point temp1 = *p1;
    Point temp2 = *p2;
    delete p1;
    delete p2;
    Segment* s = new Segment(_couleur,temp1,temp2);
    return s;
}

Segment* Segment::translation(const Vecteur &v)const{
    Point* p1 = _p1.translation(v);
    Point* p2 = _p2.translation(v);
    Point temp1 = *p1;
    Point temp2 = *p2;
    delete p1;
    delete p2;
    Segment* s = new Segment(_couleur,temp1,temp2);
    return s;
}

double Segment::aire() const{
    return 0;
}

void Segment::dessin(const Dessinable &d) const{
    d.dessinerSegment(*this);
}

string Segment::toString()const {
    ostringstream ser;
    string test = Couleurs::couleurToHexa(_couleur);
    ser.flush();
    ser << "segment: "<< _couleur << ", ";
    ser << _p1.toString() << ", " << _p2.toString();
    return ser.str();
}
