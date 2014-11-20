#ifndef VECTEUR_H
#define VECTEUR_H
#include <string>
#include <iostream>


class Vecteur{

private:

    double _x, _y;

public:


   explicit Vecteur(const double &x=0,const double &y=0);
  //  Vecteur(const Point &p1,const Point &p2);

  //  double getDeplacementX()const;
   // double getDeplacementY()const;


   // bool operator==(const Vecteur& v)const{return (_x == v._x) && (_y == v.getDeplacementY());} //// suspect

   inline const Vecteur operator+ (const Vecteur &v)const;

   inline const Vecteur operator- (const Vecteur &v)const;

    const Vecteur operator* (const double &a)const;

    inline const Vecteur operator-()const;


    double norme()const;//on garde

    operator std::string()const;

};

std::ostream& operator<<(std::ostream &, const Vecteur&);

inline const Vecteur operator* (const double &a,const Vecteur&v);
/*
Vecteur operator* (double c, const Vecteur &v);
double operator* (const Vecteur& v1,const Vecteur& v2);
*/
//--------------- mise en oeuvre des fonctions inline. --------------------------
//

inline const Vecteur Vecteur::operator+ (const Vecteur &v)const{
    return Vecteur(_x + v._x , _y + v._y);
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




#endif // VECTEUR_H
