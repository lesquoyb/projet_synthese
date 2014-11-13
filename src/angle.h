#ifndef ANGLE_H
#define ANGLE_H
#include "Tools.h"

class Angle{

private:

    double _degre;

public:

    Angle(const double degre):_degre(degre){}
    double getRadian()const{return _degre/180*tools::PI;}
    double getDegre()const{return _degre;}
    virtual ~Angle(){}
};

#endif // ANGLE_H
