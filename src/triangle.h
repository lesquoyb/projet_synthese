#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "point.h"
#include "formegeom.h"

class Triangle : public FormeGeom{

private:

    Vecteur _p1, _p2, _p3;

public:

    Triangle(const Vecteur& p1,const Vecteur&p2,const Vecteur& p3);
    Triangle(const Couleurs::Couleur & couleur,const Vecteur& p1,const Vecteur&p2,const Vecteur& p3);

    Vecteur getP1()const{return _p1;}
    Vecteur getP2()const{return _p2;}
    Vecteur getP3()const{return _p3;}

    virtual double aire()const;
    virtual string toString()const ;
    virtual Triangle* getCoordEntiere()const;
    virtual Triangle* rotation(const Vecteur &p, const Angle& angle)const;
    virtual Triangle* homothetie(const Vecteur& p, const double scale)const;
    virtual Triangle* translation(const Vecteur& v)const;
    virtual Triangle* clone()const{return new Triangle(*this);}
    virtual void dessin(const Dessinable&)const;

    friend bool operator==(const Triangle &t,const Triangle &t2);
    friend ostream& operator<<(ostream & stream, const Triangle &t);

};

#endif // TRIANGLE_H
