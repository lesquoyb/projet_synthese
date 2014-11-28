#ifndef POLYGONE_H
#define POLYGONE_H
#include "formecomposee.h"
#include "point.h"
#include <vector>
#include <algorithm>


class Polygone : public FormeComposee<Point,Polygone> {

private:

      //vector<Point> _points;

public:

    Polygone(const Couleurs::Couleur &couleur, const Point &p1, const Point &p2, const Point &p3);
    Polygone(const Point &p1,const Point &p2,const Point &p3);
    Polygone(const FormeComposee<Point,Polygone> &f);
    Polygone(const Polygone &p );

    vector<Point*> getPoints()const{return _composants;}
  //  void ajouterPoint(const Point &p){return _composants.push_back(p);}
    void ajouterPoint(Point p){return _composants.push_back(&p);}

    virtual string toString()const;
    virtual double aire()const;
    virtual Polygone* getCoordEntiere()const;

 //   virtual Polygone* rotation(const Point &p, const Angle& angle)const;
    virtual Polygone* homothetie(const Point &p, const double &scale) const;
	virtual Polygone* translation(const Vecteur& v)const;

    virtual Polygone* clone()const{return new Polygone(*this);}

    virtual void dessin(const Dessinable&)const ;


    virtual void ajouter( Point* p){_composants.push_back(p);}


    friend bool operator==(const Polygone &t,const Polygone &t2);
    friend ostream& operator<<(ostream & stream, const Polygone &t);

};

#endif // POLYGONE_H
