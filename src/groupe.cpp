#include "groupe.h"
#include <functional>
#include <algorithm>


Groupe::Groupe(const string &coul): FormeGeom(coul){}

Groupe* Groupe::rotation(const Point &p, const Angle &angle){
	Groupe* ret = new Groupe(_couleur);
	for(FormeGeom* f:composition){
        ret->ajouter(f->rotation(p,angle));
    }
	return ret;
}
void Groupe::ajouter(const FormeGeom* f){
	//TODO: vérifier qu'il n'y est pas déjà
	//TODO: changer le groupe si nécessaire
	//TODO:

}

void Groupe::supprimer(const FormeGeom* f){
	//TODO: verifier que la forme est bien dans ce groupe
	//TODO: vérifier que pointeur non null
	//TODO:
//	composition.push_back(f);

}

Groupe* Groupe::homothetie(const Point &p, const double scale){
	Groupe* g = new Groupe(*this);
	for(FormeGeom* f: g->composition){
        f->homothetie(p,scale);
    }
	return g;
}

Groupe* Groupe::translation(const Vecteur &v){
	Groupe* g = new Groupe(*this);
    for(FormeGeom* f: g->composition){
        f->translation(v);
    }
	return g;
}

void Groupe::dessin() const{
    for(const FormeGeom* f : composition){
        f->dessin();
    }
}

double Groupe::aire() const{
	//TODO avec for_each + foncteurs
    double aire = 0;
    for(const FormeGeom* f : composition){
        aire += f->aire();
    }
    return aire;
}

Groupe::~Groupe(){
    //TODO
}
