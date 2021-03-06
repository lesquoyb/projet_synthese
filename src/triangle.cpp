#include "triangle.h"


Triangle::Triangle(const Triangle &t):
    FormeGeom(t._couleur),
    _p1(t._p1),
    _p2(t._p2),
    _p3(t._p3)
    {}

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
    Point* p1 = _p1.rotation(p,angle);
    Point* p2 = _p2.rotation(p,angle);
    Point* p3 = _p3.rotation(p,angle);
    Triangle* t = new Triangle(_couleur,*p1,*p2,*p3 );
    delete p1;
    delete p2;
    delete p3;
    return t;
}

Triangle* Triangle::homothetie(const Point &p, const double &scale)const{
    Point* p1 = _p1.homothetie(p,scale);
    Point* p2 = _p2.homothetie(p,scale);
    Point* p3 = _p3.homothetie(p,scale);
    Triangle* t = new Triangle(_couleur,*p1,*p2,*p3 );
    delete p1;
    delete p2;
    delete p3;
    return t;
}

Triangle* Triangle::translation(const Vecteur &v)const{
    Point* p1 = _p1.translation(v);
    Point* p2 = _p2.translation(v);
    Point* p3 = _p3.translation(v);
    Triangle* t = new Triangle(_couleur,*p1,*p2,*p3 );
    delete p1;
    delete p2;
    delete p3;
    return t;
}

void Triangle::dessin(const Dessinable &d) const{
    d.dessinerTriangle(*this);
}


string Triangle::toString()const {
    ostringstream ser;
    ser << "triangle: " << _couleur << ", " <<  _p1.toString() << ", " << _p2.toString() << ", " << _p3.toString() ;
    return ser.str();
}





