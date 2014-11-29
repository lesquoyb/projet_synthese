#ifndef VECTEUR_H
#define VECTEUR_H
#include <string>
#include <iostream>
#include "angle.h"
#include <math.h>



class Point;
class Vecteur{

private:

    double _x, _y;

public:


   explicit Vecteur(const double &x=0,const double &y=0);
   Vecteur(const Point &p1,const Point &p2);
   Vecteur(const Vecteur &v1, const Vecteur &v2);

    double getX()const;
    double getY()const;

   Vecteur rotation(const Vecteur &p,const Angle &a)const;

   Vecteur homothetie(const Vecteur&p, double scale)const;


   bool operator==(const Vecteur& v)const{return (_x == v._x) && (_y == v._y);} //// suspect

   inline const Vecteur operator+ (const Vecteur &v)const;

   inline const Vecteur operator- (const Vecteur &v)const;

   inline double operator *(const Vecteur &v)const;

   inline const Vecteur operator* (const double &a)const;

   inline const Vecteur operator-()const;

   double norme()const;

   operator std::string()const;


};

std::ostream& operator<<(std::ostream &, const Vecteur&);


//--------------- mise en oeuvre des fonctions inline. --------------------------

inline const Vecteur Vecteur::operator+ (const Vecteur &v)const{
    return Vecteur(_x + v._x , _y + v._y);
}

inline const Vecteur Vecteur::operator* (const double &a)const{
    return Vecteur(a*_x , a*_y);
}


inline const Vecteur operator* (const double &a,const Vecteur&v){
    return v*a;
}


inline const Vecteur Vecteur::operator-()const{
    return Vecteur(-_x,-_y);
}

inline const Vecteur Vecteur::operator- (const Vecteur &v)const{
    return *this+ -v;
}

double Vecteur::operator* (const Vecteur &v)const{
    return (_x * v._x + _y * v._y) ;
}


#endif // VECTEUR_H
