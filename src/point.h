#ifndef POINT_H
#define POINT_H
#include "formegeom.h"
#include <cmath>

class Point{

private:

    double _x, _y;

public:

    Point(const Point&);
    Point(double x, double y);

    Point* translation(const Vecteur& v);
    Point* rotation(const Point &p,const Angle &a){

    }


    double getDist(const Point &p){
        return sqrt( pow(_x - p._x,2) + pow(_y - p._y,2) );
    }

    bool operator==(const Point&p)const{
        return (_x == p._x) &&(_y == p._y);
    }
    friend ostream& operator<<(ostream& , const Point &);

    double getX()const{return _x;}
    double getY()const{return _y;}

};



#endif // POINT_H
