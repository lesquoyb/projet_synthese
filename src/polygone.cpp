#include "polygone.h"
#include <algorithm>

Polygone::Polygone(const Couleurs::Couleur &couleur, const Vecteur &p1, const Vecteur &p2, const Vecteur &p3):
FormeGeom(couleur)
{
    _points.push_back(p1);
    _points.push_back(p2);
    _points.push_back(p3);
}

Polygone::Polygone(const Vecteur &p1, const Vecteur &p2, const Vecteur &p3){
    _points.push_back(p1);
    _points.push_back(p2);
    _points.push_back(p3);
}


Polygone* Polygone::getCoordEntiere()const{
    Polygone* poly = new Polygone(*this);
    unsigned i = 0;
    for(Vecteur p : _points){
        poly->_points[i] = p.getCoordEntieres();
        i++;
    }
    return poly;
}


Polygone::Polygone(const Polygone &p):
FormeGeom(p._couleur),
_points(p._points)
{}

double Polygone::aire() const{
    double somme = 0;
    for(unsigned int i = 0 ; i < _points.size()-1 ; i ++){
        Vecteur temp(_points[i]);
        Vecteur next(_points[i+1]);
        somme += (temp.getX() * next.getY() - next.getX()*temp.getY());
    }
    Vecteur dern(_points[_points.size()-1]);
    Vecteur prem(_points[0]);
    somme += (dern.getX() * prem.getY() - prem.getX()*dern.getY());
    return abs(somme/2);
}

Polygone* Polygone::rotation(const Vecteur &p, const Angle &angle)const{
    Polygone* poly = new Polygone(*this);
    for(unsigned int i = 0; i < _points.size(); i++ ){
        Vecteur temp(_points[i].rotation(p,angle));
        poly->_points[i] = temp;
    }
    return poly;
}

Polygone* Polygone::homothetie(const Vecteur &p, const double scale)const{
    Polygone* poly = new Polygone(*this);
    for(unsigned int i = 0; i < _points.size(); i++ ){
        Vecteur temp(_points[i].homothetie(p,scale));
        poly->_points[i] = temp;
    }
    return poly;
}

Polygone* Polygone::translation(const Vecteur &v)const{
    Polygone* poly = new Polygone(*this);
    for(unsigned int i = 0; i < _points.size(); i++ ){
        Vecteur temp(_points[i] + v);
        poly->_points[i] = temp;
    }
    return poly;
}

void Polygone::dessin(const Dessinable &d) const{
    d.dessinerPolygone(*this);
}

string Polygone::toString()const {
    ostringstream ser;
    ser << "polygone: " << _couleur << ", ";
    for(Vecteur point : _points){
        ser << point.getX() << ", " << point.getY() << ", ";
    }
    return ser.str().substr(0,ser.str().length()- 2); // on enlève 2 car c'est la taille du dernier ", "
}



bool operator==(const Polygone &t,const Polygone &t2){
    if( (t._points.size() != t2._points.size()) or (t._couleur != t2._couleur) ){
        return false;
    }
    for(unsigned int i = 0; i < t._points.size(); i++){
        if(! (t._points[i] == t2._points[i])){
            return false;
        }
    }
    return true;
}


ostream& operator<<(ostream & stream, const Polygone &p){
    stream << p.toString();
    return stream;
}




