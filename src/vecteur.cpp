#include <sstream>
#include "point.h"
#include "vecteur.h"

using namespace std;


Vecteur::Vecteur(const double &x, const double &y):
    _x(x),
    _y(y)
    {}

Vecteur::Vecteur(const Point &p1, const Point & p2):
    _x( p2.getX() - p1.getX()),
    _y( p2.getY() - p1.getY())
    {}

double Vecteur::getX() const{
    return _x;
}

double Vecteur::getY() const{
    return _y;
}

std::ostream& operator<<(std::ostream &stream, const Vecteur&v){
    stream << (string) v;
    return stream;
}

double Vecteur::norme()const{
    return sqrt( pow(_x,2) + pow(_y,2) );
}

Vecteur::operator string()const{
    ostringstream oss;
    oss << "( " << _x << ", " << _y << ") ";
    return oss.str();
}


