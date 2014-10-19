#include "groupe.h"
#include <functional>
#include <algorithm>


Groupe::Groupe(const string &coul): FormeGeom::FormeGeom(coul){}

void Groupe::rotation(const Point &p, const Angle &angle){
   //TODO with for_each and bind
}

void Groupe::homothetie(const Point &p, const double scale){
//TODO with for_each and bind
}

void Groupe::translation(const Vecteur &v){
//TODO with for_each and bind
}

void Groupe::dessin() const{
//TODO with for_each and bind
}

double Groupe::aire() const{
//TODO with for_each and bind
    return 0;
}

Groupe::~Groupe(){
    //TODO
}
