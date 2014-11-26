#ifndef POLYGONE_H
#define POLYGONE_H
#include "formegeom.h"
#include "point.h"
#include <vector>
#include <algorithm>


class Polygone : public FormeGeom{

private:

    vector<Point> _points;

public:

    Polygone(const Couleurs::Couleur &couleur,const Vecteur &p1, const Vecteur &p2, const Vecteur &p3);
    Polygone(const Vecteur &p1, const Vecteur &p2, const Vecteur &p3);
	Polygone(const Polygone&);

    vector<Point> getPoints()const{return _points;}
    void ajouterPoint(const Point &p){return _points.push_back(p);}


    virtual string toString()const;
    virtual double aire()const;
    virtual Polygone* getCoordEntiere()const;
    virtual Polygone* rotation(const Point &p, const Angle& angle)const;
    virtual Polygone* homothetie(const Point &p, const double scale) const;
	virtual Polygone* translation(const Vecteur& v)const;
    virtual Polygone* clone()const{return new Polygone(*this);}
    virtual void dessin(const Dessinable&)const ;


    friend bool operator==(const Polygone &t,const Polygone &t2);
    friend ostream& operator<<(ostream & stream, const Polygone &t);

};

#endif // POLYGONE_H
