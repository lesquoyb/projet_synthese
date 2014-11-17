#include "polygone.h"
#include <algorithm>

Polygone::Polygone(const string &couleur, const Point &p1, const Point &p2, const Point &p3):
FormeGeom(couleur)
{
    _points.push_back(p1);
    _points.push_back(p2);
    _points.push_back(p3);
}

Polygone::Polygone(const Point &p1, const Point &p2, const Point &p3){
    _points.push_back(p1);
    _points.push_back(p2);
    _points.push_back(p3);
}


Polygone* Polygone::getCoordEntiere()const{
    Polygone* poly = new Polygone(*this);
    unsigned i = 0;
    for(Point p : _points){
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
        Point temp(_points[i]);
        Point next(_points[i+1]);
        somme += (temp.getX() * next.getY() - next.getX()*temp.getY());
    }
    Point dern(_points[_points.size()-1]);
    Point prem(_points[0]);
    somme += (dern.getX() * prem.getY() - prem.getX()*dern.getY());
    return abs(somme/2);
}

Polygone* Polygone::rotation(const Point &p, const Angle &angle)const{
    Polygone* poly = new Polygone(*this);
    for(unsigned int i = 0; i < _points.size(); i++ ){
        Point temp(_points[i].rotation(p,angle));
        poly->_points[i] = temp;
    }
    return poly;
}

Polygone* Polygone::homothetie(const Point &p, const double scale)const{
    Polygone* poly = new Polygone(*this);
    for(unsigned int i = 0; i < _points.size(); i++ ){
        Point temp(_points[i].homothetie(p,scale));
        poly->_points[i] = temp;
    }
    return poly;
}

Polygone* Polygone::translation(const Vecteur &v)const{
    Polygone* poly = new Polygone(*this);
    for(unsigned int i = 0; i < _points.size(); i++ ){
        Point temp(_points[i].translation(v));
        poly->_points[i] = temp;
    }
    return poly;
}

void Polygone::dessin(const Dessinable &d) const{
    d.dessinerPolygone(*this);
}

string Polygone::toString()const {
    ostringstream ser;
    ser << "polygone: " << Couleurs::stringToHexa(_couleur) << ", ";
    for(Point point : _points){
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




