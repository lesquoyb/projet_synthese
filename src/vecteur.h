#ifndef VECTEUR_H
#define VECTEUR_H

#include <iostream>

class Point;

class Vecteur{

private:

    double _deplacementX, _deplacementY;
public:

    Vecteur(double deplacementX, double deplacementY);
    Vecteur(const Point &p1,const Point &p2);

    double getDeplacementX()const;
    double getDeplacementY()const;

    friend Vecteur operator* (double c, const Vecteur &v);
    friend double operator* (const Vecteur& v1,const Vecteur& v2);

    bool operator==(const Vecteur& v)const{return (_deplacementX == v._deplacementX) && (_deplacementY == v.getDeplacementY());}
    friend std::ostream& operator<<(std::ostream &, const Vecteur&);

    double norme()const;

};

#endif // VECTEUR_H
