#include "triangle.h"


Triangle::Triangle(const Point &p1, const Point &p2, const Point &p3):
    FormeGeom(),
    _p1(p1),
    _p2(p2),
    _p3(p3)
    {}

Triangle::Triangle(const Couleurs::Couleur &couleur, const Point &p1, const Point &p2, const Point &p3):
    FormeGeom(couleur),
    _p1(p1),
    _p2(p2),
    _p3(p3)
    {}

Triangle* Triangle::clone()const{
    return new Triangle(*this);
}


/**
 * @brief Triangle::aire
 * Calcule l'aire du triangle grâce à la méthode de Héron
 * @return l'aire
 */
double Triangle::aire() const{
    double distP1P2 = Vecteur(_p1,_p2).norme();
    double distP1P3 = Vecteur(_p1,_p3).norme();
    double distP3P2 = Vecteur(_p2,_p3).norme();
    double demiPerimetre = (distP1P2 + distP1P3 + distP3P2) / 2;
    return sqrt( demiPerimetre * (demiPerimetre - distP1P2) * (demiPerimetre - distP1P3) * (demiPerimetre - distP3P2) );
}

Triangle* Triangle::rotation(const Point &p, const Angle &angle)const{
    return new Triangle(*_p1.rotation(p,angle),*_p2.rotation(p,angle),*_p3.rotation(p,angle));
}

Triangle* Triangle::homothetie(const Point &p, const double &scale)const{
    return new Triangle(*_p1.homothetie(p,scale),*_p2.homothetie(p,scale),*_p3.homothetie(p,scale));
}

Triangle* Triangle::translation(const Vecteur &v)const{
    return new Triangle(*_p1.translation(v),*_p2.translation(v),*_p3.translation( v) );
}

void Triangle::dessin(const Dessinable &d) const{
    d.dessinerTriangle(*this);
}


string Triangle::toString()const {
    ostringstream ser;
    ser << "triangle: " << _couleur << ", " <<  _p1.getX() << ", " << _p1.getY() << ", " << _p2.getX() << ", " << _p2.getY() << ", " << _p3.getX() << ", " << _p3.getY() ;
    return ser.str(); // on enlève 2 car c'est la taille du dernier ", "
}





