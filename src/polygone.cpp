#include "polygone.h"

Polygone::Polygone()
{
}

double Polygone::aire() const
{
	//TODO
	return 0;
}

Polygone* Polygone::rotation(const Point &p, const Angle &angle)
{
	//TODO:
	return new Polygone(*this);
}

Polygone* Polygone::homothetie(const Point &p, const double scale)
{
	//TODO:
	return new Polygone(*this);
}

Polygone* Polygone::translation(const Vecteur &v)
{
	//TODO:
	return new Polygone(*this);
}

void Polygone::dessin() const{
    //for_each(points.begin(),points.end();   );
}
