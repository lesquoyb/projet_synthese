#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "point.h"
#include "formegeom.h"

class Triangle : public FormeGeom{

private:

    Point _p1, _p2, _p3;

public:

    Triangle(const Point &p1,const Point &p2,const Point &p3);
    Triangle(const Couleurs::Couleur & couleur,const Point &p1,const Point &p2,const Point &p3);

    inline Point getP1()const;
    inline Point getP2()const;
    inline Point getP3()const;

    //Objetgeom
    virtual string toString()const ;
    virtual Triangle* rotation(const Point &p, const Angle& angle)const;
    virtual Triangle* homothetie(const Point &p, const double &scale)const;
    virtual Triangle* translation(const Vecteur& v)const;
    //FormeGeom
    virtual double aire()const;
    virtual Triangle* clone()const;
    virtual void dessin(const Dessinable&)const;


};


inline Point Triangle::getP1()const{return _p1;}
inline Point Triangle::getP2()const{return _p2;}
inline Point Triangle::getP3()const{return _p3;}

#endif // TRIANGLE_H
