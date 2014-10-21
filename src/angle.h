#ifndef ANGLE_H
#define ANGLE_H

class Angle
{
private:
    double radian;
    Angle();

public:
    Angle(const double a);
    double getRadian()const;
    double getDegree()const;
    virtual ~Angle();
};

#endif // ANGLE_H
