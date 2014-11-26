#ifndef OBJETGEOM_H
#define OBJETGEOM_H

class Vecteur;
class Angle;
class Groupe;
class Point;

class ObjetGeom{

public:


    virtual ObjetGeom* rotation(const Point &p, const Angle& angle)const = 0;
    virtual ObjetGeom* homothetie(const Point &p, const double scale)const = 0;
    virtual ObjetGeom* translation(const Vecteur& v)const = 0;


};

#endif // OBJETGEOM_H
