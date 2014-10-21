#ifndef POLYGONE_H
#define POLYGONE_H
#include "formegeom.h"
#include "point.h"
#include <vector>

class Polygone : public FormeGeom{

private:

    vector<Point> points;

public:

    Polygone();
    virtual double aire()const;
    virtual void rotation(const Point &p, const Angle& angle);
    virtual void homothetie(const Point& p, const double scale) ;
    virtual void translation(const Vecteur& v);
    virtual void dessin()const ;

};

#endif // POLYGONE_H
