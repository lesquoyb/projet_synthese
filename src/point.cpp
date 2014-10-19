#include "point.h"



Point::Point(const string &c) : FormeGeom(c) {}

Point::Point(double x, double y, const string &c):
FormeGeom(c),
_x(x),
_y(y)
{}

void Point::rotation(const Point &p,const Angle &angle){
  //TODO
}

void Point::homothetie(const Point &p, const double scale){
    double distX = sqrt( 50);
}

void Point::translation(const Vecteur &v){
    //TODO
}

void Point::dessin(){
    //TODO
}
