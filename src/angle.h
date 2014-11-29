#ifndef ANGLE_H
#define ANGLE_H

class Angle{

private:

    double _degre;

public:


    static constexpr double PI= 3.14159265359;

    Angle(const double degre):_degre(degre){}

    inline double getRadian()const;
    inline double getDegre()const;

    virtual ~Angle(){}
};


inline double Angle::getDegre()const{return _degre;}

inline double Angle::getRadian()const{return _degre/180*PI;}


#endif // ANGLE_H
