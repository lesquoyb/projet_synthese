#include "groupe.h"
#include <functional>
#include <algorithm>


Groupe::Groupe(const string &coul): FormeGeom::FormeGeom(coul){}

void Groupe::rotation(const Point &p, const Angle &angle){
    for(FormeGeom* f:composition){
        f->rotation(p,angle);
    }
}

void Groupe::homothetie(const Point &p, const double scale){
    for(FormeGeom* f:composition){
        f->homothetie(p,scale);
    }
}

void Groupe::translation(const Vecteur &v){
    for(FormeGeom* f:composition){
        f->translation(v);
    }
}

void Groupe::dessin() const{
    for(const FormeGeom* f : composition){
        f->dessin();
    }
}

double Groupe::aire() const{
    double aire = 0;
    for(const FormeGeom* f : composition){
        aire += f->aire();
    }
    return aire;
}

Groupe::~Groupe(){
    //TODO
}
