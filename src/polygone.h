#ifndef POLYGONE_H
#define POLYGONE_H
#include "formegeom.h"
#include "point.h"
#include <vector>


class Polygone : public FormeGeom{

private:

    vector<Point> _points;

public:

    Polygone(const string &couleur);
	Polygone(const Polygone&);

    vector<Point> getPoints()const{return _points;}
    void ajouterPoint(const Point &p){return _points.push_back(p);}

    virtual string serialisation()const;
    virtual double aire()const;
	virtual Polygone* rotation(const Point &p, const Angle& angle)const;
	virtual Polygone* homothetie(const Point& p, const double scale) const;
	virtual Polygone* translation(const Vecteur& v)const;
    virtual void dessin(const Dessinable&)const ;


};

#endif // POLYGONE_H
