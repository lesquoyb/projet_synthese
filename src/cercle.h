#ifndef CERCLE_H
#define CERCLE_H
#include "formegeom.h"


class Cercle : public FormeGeom{

private:

    Point _centre;
    double _rayon;

public:

    Cercle(const Point &centre, double rayon);
    Cercle(const Couleurs::Couleur &couleur, const Point &centre, double rayon);

    inline Point getCentre()const;
    inline double getRayon()const;

    //ObjetGeom
    virtual Cercle* rotation(const Point &p, const Angle& angle) const;
    virtual Cercle* homothetie(const Point &p, const double &scale)const ;
    virtual Cercle* translation(const Vecteur& v)const ;
    virtual string toString()const;
    //FormeGeom
    virtual double aire()const ;
    virtual void dessin(const Dessinable&)const;
    virtual Cercle* clone()const{return new Cercle(*this);}

};



inline Point Cercle::getCentre()const{return _centre;}
inline double Cercle::getRayon()const{return _rayon;}

#endif // CERCLE_H
