#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "point.h"
#include "formegeom.h"

class Triangle : public FormeGeom{

private:

    Point _p1, _p2, _p3;

public:

    Triangle(const Point& p1,const Point&p2,const Point& p3);
    Triangle(const Couleurs::Couleur & couleur,const Point& p1,const Point&p2,const Point& p3);

    Point getP1()const{return _p1;}
    Point getP2()const{return _p2;}
    Point getP3()const{return _p3;}

    virtual double aire()const;
    virtual string toString()const ;
    virtual Triangle* getCoordEntiere()const;
    virtual Triangle* rotation(const Point &p, const Angle& angle)const;
    virtual Triangle* homothetie(const Point& p, const double scale)const;
    virtual Triangle* translation(const Vecteur& v)const;
    virtual Triangle* clone()const{return new Triangle(*this);}
    virtual void dessin(const Dessinable&)const;

    friend bool operator==(const Triangle &t,const Triangle &t2);
    friend ostream& operator<<(ostream & stream, const Triangle &t);

};

#endif // TRIANGLE_H
