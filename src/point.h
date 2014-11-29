#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <cmath>
#include "angle.h"
#include "vecteur.h"
#include "objetgeom.h"


using namespace std;


class Point :public ObjetGeom{

private:

    Vecteur _coord;

public:

    Point(const Point &p);
    explicit Point(const Vecteur&);
    explicit Point(double x, double y);

    Vecteur getCoord()const {return _coord;}

    inline double getX()const;
    inline double getY()const;

    double getDist(const Point &p)const;

    virtual Point* rotation(const Point &p, const Angle &a) const;
    virtual Point* homothetie(const Point &p,const double &scale) const;
    virtual Point* translation(const Vecteur &v)const;
    virtual string toString()const;

};


inline double Point::getX()const{return _coord.getX();}
inline double Point::getY()const{return _coord.getY();}


#endif // POINT_H
