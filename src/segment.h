#ifndef SEGMENT_H
#define SEGMENT_H
#include "point.h"


class Segment : public FormeGeom{

private:

    Point _p1, _p2;

public:

    Segment(const string& couleur,const Point& p, const Point &p2);

    Point getPoint1()const{return _p1;}
    Point getPoint2()const{return _p2;}

    virtual string serialisation()const;
	virtual Segment* rotation(const Point &p, const Angle& angle) const;
	virtual Segment* homothetie(const Point& p, const double scale)const;
	virtual Segment* translation(const Vecteur& v)const;
    virtual double aire() const;
    virtual void dessin() const;




};

#endif // SEGMENT_H
