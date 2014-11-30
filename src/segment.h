#ifndef SEGMENT_H
#define SEGMENT_H
#include "formegeom.h"


class Segment : public FormeGeom{

private:

    Point _p1, _p2;

public:

    Segment(const Couleurs::Couleur& couleur,const Point& p, const Point &p2 );
    Segment( const Point &p, const Point &p2);

    inline Point getPoint1()const;
    inline Point getPoint2()const;

    //ObjetGeom
    virtual string toString()const;
    virtual Segment* rotation(const Point &p, const Angle& angle) const;
    virtual Segment* homothetie(const Point &p, const double &scale)const;
    virtual Segment* translation(const Vecteur& v)const;
    //FormeGeom
    virtual double aire() const;
    virtual Segment* clone()const{return new Segment(*this);}
    virtual void dessin(const Dessinable&) const;

    virtual ~Segment(){}

};

inline Point Segment::getPoint1()const{return _p1;}
inline Point Segment::getPoint2()const{return _p2;}



#endif // SEGMENT_H
