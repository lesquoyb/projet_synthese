#include "segment.h"


Segment::Segment(const string &couleur, const Point &p, const Point &p2):
FormeGeom(couleur),
_p1(p),
_p2(p2)
{}

Segment* Segment::rotation(const Point &p, const Angle &angle)const{
	//TODO
	return new Segment(*this);
}

Segment* Segment::homothetie(const Point &p, const double scale)const{
	//TODO
	return new Segment(*this);
}

Segment* Segment::translation(const Vecteur &v)const{
	return new Segment(_couleur, *_p1.translation(v), *_p2.translation(v) );
}

double Segment::aire() const{
    return 0;
}

void Segment::dessin() const{
    //TODO
}

Point Segment::getPoint1() const{
    return _p1;
}

Point Segment::getPoint2() const{
    return _p2;
}
