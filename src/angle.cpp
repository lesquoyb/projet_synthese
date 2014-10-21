#include "angle.h"
#include "Tools.h"

Angle::Angle(){}

Angle::Angle(const double a):radian(a){}

double Angle::getRadian()const{
    return radian;
}

double Angle::getDegree() const
{
    return (radian*180) / PI;
}

Angle::~Angle(){}
