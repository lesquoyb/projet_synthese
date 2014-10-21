#ifndef POINT_H
#define POINT_H
#include "formegeom.h"


class Point : public FormeGeom{

private:

    double _x, _y;
    Point();

public:

    Point(const string &c);
    Point(const Point&);
    Point( const string &c,double x, double y);
    virtual void rotation(const Point &p,const Angle& angle) ;
    virtual void homothetie(const Point& p, const double scale);
    virtual void translation(const Vecteur& v);
    virtual double aire() const;
    virtual void dessin() const;
    bool operator==(const Point&p)const;
    friend ostream& operator<<(ostream& , const Point &);

    double getX()const;
    double getY()const;

};



#endif // POINT_H
