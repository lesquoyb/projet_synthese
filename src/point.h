#ifndef POINT_H
#define POINT_H
#include "formegeom.h"


class Point : public FormeGeom{

private:

    double _x, _y;

public:
    Point(const string &c);
    Point(double x, double y, const string &c);
    virtual void rotation(const Point &p,const Angle& angle) ;
    virtual void homothetie(const Point& p, const double scale);
    virtual void translation(const Vecteur& v);
    virtual void dessin();

};

#endif // POINT_H
