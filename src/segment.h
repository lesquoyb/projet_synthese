#ifndef SEGMENT_H
#define SEGMENT_H
#include "point.h"


class Segment : public FormeGeom{

private:

    Point _p1, _p2;

    Segment();

public:

    Segment(const string& couleur,const Point& p, const Point &p2);
    virtual Segment* rotation(const Point &p,const Angle& angle) ;
    virtual Segment* homothetie(const Point& p, const double scale);
    virtual Segment* translation(const Vecteur& v);
    virtual double aire() const;
    virtual void dessin() const;

    Point getPoint1()const;
    Point getPoint2()const;



};

#endif // SEGMENT_H
