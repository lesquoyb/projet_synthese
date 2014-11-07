#include "polygone.h"

Polygone::Polygone(const Polygone &p){
	this->_couleur = p._couleur;
	//TODO
}
double Polygone::aire() const
{
	//TODO
	return 0;
}

Polygone* Polygone::rotation(const Point &p, const Angle &angle)const{
	//TODO:
	return new Polygone(*this);
}

Polygone* Polygone::homothetie(const Point &p, const double scale)const{
	//TODO:
	return new Polygone(*this);
}

Polygone* Polygone::translation(const Vecteur &v)const{
	//TODO:
	return new Polygone(*this);
}

void Polygone::dessin() const{
    //for_each(points.begin(),points.end();   );
}
