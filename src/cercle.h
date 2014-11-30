#ifndef CERCLE_H
#define CERCLE_H
#include "formegeom.h"

/**
 * @brief The Cercle class
 * Cette classe représente un cercle, c'est à dire un point pour le centre et un double représentant le rayon.
 */
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

    virtual ~Cercle(){}

};



inline Point Cercle::getCentre()const{return _centre;}
inline double Cercle::getRayon()const{return _rayon;}

#endif // CERCLE_H
