#include "polygone.h"
#include <algorithm>

Polygone::Polygone(const Couleurs::Couleur &couleur, const Point &p1, const Point &p2, const Point &p3):
FormeComposee(couleur){
    //TODO: vérifs, sinon exception
    _composants.push_back(new Point(p1));
    _composants.push_back(new Point(p2));
    _composants.push_back(new Point(p3));
}

Polygone::Polygone(const Point &p1, const Point &p2, const Point &p3){
    //TODO: vérif, sinon exception
    _composants.push_back(new Point(p1));
    _composants.push_back(new Point(p2));
    _composants.push_back(new Point(p3));
}



Polygone*  Polygone::clone() const{
    return new Polygone(*this);
}


Polygone::Polygone(const FormeComposee<Point,Polygone> &f):
FormeComposee<Point,Polygone>(f.getCouleur())
{
    for (size_t i = 0; i < f.getComposants().size(); ++i){
       _composants.push_back(f.getComposants()[i]);
    }

}



double Polygone::aire() const{
    double somme = 0;
    for(size_t i = 0 ; i < _composants.size()-1 ; i ++){
        Point temp(*_composants[i]);
        Point next(*_composants[i+1]);
        somme += (temp.getX() * next.getY() - next.getX()*temp.getY());
    }
    Point dern(*_composants.back());//[_composants.size()-1]);
    Point prem(*_composants[0]);
    somme += (dern.getX() * prem.getY() - prem.getX()*dern.getY());
    return abs(somme/2);
}



Polygone::Polygone(const Polygone &p ):
    FormeComposee<Point,Polygone>(p._couleur,p.getComposants())
{}



void Polygone::dessin(const Dessinable &d) const{
    d.dessinerPolygone(*this);
}

/**
 * @brief Polygone::~Polygone
 * On doit supprimer les membres du vector car il s'agit de copies créées par l'instance.
 */
Polygone::~Polygone(){
    for(Point* p : _composants){
            delete p;
    }
}

string Polygone::toString()const {
    ostringstream ser;
    ser << "polygone: " << _couleur << ", ";
    for(Point* point : _composants){
        ser << point->toString() << ", ";
    }
    string message = ser.str();
    int i = message.length() - 2 ; // on enlève 2 car c'est la taille du dernier ", "
    string inter = message.substr(0, i);
    return inter;
}




