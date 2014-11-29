#ifndef OBJETGEOM_H
#define OBJETGEOM_H
#include <string>


class Vecteur;
class Angle;
class Point;

class ObjetGeom{

public:



    virtual ObjetGeom* rotation(const Point &p, const Angle& angle)const = 0;
    virtual ObjetGeom* homothetie(const Point &p, const double &scale)const = 0;
    virtual ObjetGeom* translation(const Vecteur& v)const = 0;
    virtual std::string toString()const = 0;

    virtual ~ObjetGeom(){}

};

#endif // OBJETGEOM_H
