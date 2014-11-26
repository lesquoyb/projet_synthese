#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <cmath>
#include "angle.h"
#include "vecteur.h"
#include "objetgeom.h"


using namespace std;


class Point :public ObjetGeom{

private:

    Vecteur _coord;

public:

    Point(const Point &p);
    Point(const Vecteur&);
    Point(double x, double y);

    Vecteur getCoord()const {return _coord;}



    bool operator==(const Point &p)const;



    friend ostream& operator<<(ostream& , const Point &);

    inline Point getCoordEntieres()const;
    inline double getX()const;
    inline double getY()const;

    double getDist(const Point &p)const;




    virtual Point* rotation(const Point &p, const Angle &a) const;
    virtual Point* homothetie(const Point &p, double scale) const;
    virtual Point* translation(const Vecteur &v)const;


};

inline Point Point::getCoordEntieres()const{
    return Point(round(_coord.getX()),round(_coord.getY()));
}


inline double Point::getX()const{return _coord.getX();}
inline double Point::getY()const{return _coord.getY();}


#endif // POINT_H
