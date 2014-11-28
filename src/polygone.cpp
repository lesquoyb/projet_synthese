#include "polygone.h"
#include <algorithm>

Polygone::Polygone(const Couleurs::Couleur &couleur, const Point &p1, const Point &p2, const Point &p3):
FormeComposee(couleur){
    _composants.push_back(new Point(p1));
    _composants.push_back(new Point(p2));
    _composants.push_back(new Point(p3));
}

Polygone::Polygone(const Point &p1, const Point &p2, const Point &p3){
    _composants.push_back(new Point(p1));
    _composants.push_back(new Point(p2));
    _composants.push_back(new Point(p3));
}


Polygone* Polygone::getCoordEntiere()const{
    Polygone* poly = new Polygone(*this);
    unsigned i = 0;
    for(Point* p : _composants){
        poly->_composants[i] = new Point(p->getCoordEntieres());
        i++;
    }
    return poly;
}


Polygone::Polygone(const FormeComposee<Point,Polygone> &f):
    //TODO test
FormeComposee<Point,Polygone>(f.getCouleur())
{
    for (size_t i = 0; i < f.getComposants().size(); ++i){
       _composants.push_back(f.getComposants()[i]);
    }

}



double Polygone::aire() const{
    double somme = 0;
    for(unsigned int i = 0 ; i < _composants.size()-1 ; i ++){
        Point temp(*_composants[i]);
        Point next(*_composants[i+1]);
        somme += (temp.getX() * next.getY() - next.getX()*temp.getY());
    }
    Point dern(*_composants[_composants.size()-1]);
    Point prem(*_composants[0]);
    somme += (dern.getX() * prem.getY() - prem.getX()*dern.getY());
    return abs(somme/2);
}

/*
Polygone* Polygone::rotation(const Point &p, const Angle &angle)const{
    Polygone* poly = new Polygone(*this);
    for(unsigned int i = 0; i < _points.size(); i++ ){
        Point temp(*_points[i].rotation(p,angle));
        poly->_points[i] = temp;
    }
    return poly;
}

*/


Polygone* Polygone::homothetie(const Point &p, const double &scale)const{
    Polygone* poly = new Polygone(*this);
    for(unsigned int i = 0; i < _composants.size(); i++ ){
        Point temp(*_composants[i]->homothetie(p,scale));
        poly->_composants[i] = new Point(temp);
    }
    return poly;
}

Polygone* Polygone::translation(const Vecteur &v)const{
    Polygone* poly = new Polygone(*this);
    for(unsigned int i = 0; i < _composants.size(); i++ ){
        poly->_composants[i] = _composants[i]->translation(v);
    }
    return poly;
}

Polygone::Polygone(const Polygone &p ):
    FormeComposee<Point,Polygone>(p._couleur,p.getComposants())
{}

void Polygone::dessin(const Dessinable &d) const{
    d.dessinerPolygone(*this);
}

string Polygone::toString()const {
    ostringstream ser;
    ser << "polygone: " << _couleur << ", ";
    for(Point* point : _composants){
        ser << point->getX() << ", " << point->getY() << ", ";
    }
    return ser.str().substr(0,ser.str().length()- 2); // on enlève 2 car c'est la taille du dernier ", "
}



bool operator==(const Polygone &t,const Polygone &t2){
    if( (t._composants.size() != t2._composants.size()) or (t._couleur != t2._couleur) ){
        return false;
    }
    for(unsigned int i = 0; i < t._composants.size(); i++){
        if(! (*t._composants[i] == *t2._composants[i])){
            return false;
        }
    }
    return true;
}


ostream& operator<<(ostream & stream, const Polygone &p){
    stream << p.toString();
    return stream;
}




