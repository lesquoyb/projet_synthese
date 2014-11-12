#include "polygone.h"
#include <algorithm>

Polygone::Polygone(const string &couleur):
FormeGeom(couleur)
{}

Polygone::Polygone(const Polygone &p):
FormeGeom(p._couleur),
_points(p._points)
{//TODO
}

double Polygone::aire() const{
    //TODO:
    return 0;
}

Polygone* Polygone::rotation(const Point &p, const Angle &angle)const{
    //TODO:tester
    Polygone* poly = new Polygone(*this);
    for_each(poly->_points.begin(),poly->_points.end(), [p,angle] (Point obj){obj.rotation(p,angle);});
    return poly;
}

Polygone* Polygone::homothetie(const Point &p, const double scale)const{
    //TODO:tester
    Polygone* poly = new Polygone(*this);
    for_each(poly->_points.begin(),poly->_points.end(), [p,scale] (Point obj){obj.homothetie(p,scale);});
    return poly;
}

Polygone* Polygone::translation(const Vecteur &v)const{
    //TODO tester
    Polygone* p = new Polygone(*this);
    for_each(p->_points.begin(),p->_points.end(), [v] (Point obj){obj.translation(v);});
    return p;
}

void Polygone::dessin(const Dessinable &d) const{
    d.dessinerPolygone(*this);
}

string Polygone::serialisation()const {
    ostringstream ser;
    ser << "polygone: " << Couleurs::stringToHexa(_couleur) << ", ";
    for(Point point : _points){
        ser << point.getX() << ", " << point.getY() << ", ";
    }
    return ser.str().substr(0,ser.str().length()- 2); // on enlève 2 car c'est la taille du dernier ", "
}
