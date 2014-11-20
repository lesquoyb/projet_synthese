#include <sstream>

#include "vecteur.h"

using namespace std;


Vecteur::Vecteur(const double &x, const double &y):

    _x(x),
    _y(y)
    {}
/*
Vecteur::Vecteur(const Point &p1, const Point & p2):
    _x( p2.getX() - p1.getX()),
    _y( p2.getY() - p1.getY())
    {}

double Vecteur::getDeplacementX() const{
    return _x;
}

double Vecteur::getDeplacementY() const{
    return _y;
}


Vecteur operator* (double c, const Vecteur &v){
    return Vecteur(v.getDeplacementX()*c , v.getDeplacementY()*c);
}
*/
std::ostream& operator<<(std::ostream &stream, const Vecteur&v){
    stream << (string) v;
    return stream;
}

/*
double Vecteur::norme()const{
    return sqrt( pow(_x,2) + pow(_y,2) );
}


double operator* (const Vecteur &v1,const Vecteur& v2){
    return v1._x*v2._x + v1._y*v2._y;
}
*/


Vecteur::operator string()const{
    ostringstream oss;
    oss << "( " << _x << ", " << _y << ") ";
    return oss.str();
}

const Vecteur Vecteur::operator* (const double &a)const{
    return Vecteur(a*_x , a*_y);
}


