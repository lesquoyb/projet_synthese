#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "formegeom.h"
#include "point.h"

class Triangle : public FormeGeom{

private:

    Point _p1, _p2, _p3;
    Triangle();

public:

    Triangle(const Point& p1,const Point&p2,const Point& p3);
    Triangle(const string& couleur,const Point& p1,const Point&p2,const Point& p3);
    virtual double aire()const;
    virtual void rotation(const Point &p, const Angle& angle);
    virtual void homothetie(const Point& p, const double scale);
    virtual void translation(const Vecteur& v);
    virtual void dessin()const;

};

#endif // TRIANGLE_H
