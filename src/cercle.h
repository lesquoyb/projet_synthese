#ifndef CERCLE_H
#define CERCLE_H
#include "formegeom.h"


class Cercle : public FormeGeom{

private:

    Vecteur _centre;
    double _rayon;

public:

    Cercle(const Vecteur& centre,double rayon);
    Cercle(const Couleurs::Couleur &couleur, const Vecteur& centre, double rayon);

    Vecteur getCentre()const{return _centre;}
    double getRayon()const{return _rayon;}

    virtual string toString()const;
    virtual Cercle* getCoordEntiere()const;
    virtual double aire()const ;
    virtual Cercle* rotation(const Vecteur &p, const Angle& angle) const;
    virtual Cercle* homothetie(const Vecteur& p, const double scale)const ;
    virtual Cercle* translation(const Vecteur& v)const ;
    virtual void dessin(const Dessinable&)const;
    virtual Cercle* clone()const{return new Cercle(*this);}

    friend bool operator==(const Cercle &t,const Cercle &t2);
    friend ostream& operator<<(ostream & stream, const Cercle &t);
};

#endif // CERCLE_H
