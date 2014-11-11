#include "groupe.h"
#include <functional>
#include <algorithm>


Groupe::Groupe(const string &coul): FormeGeom(coul){}

Groupe* Groupe::rotation(const Point &p, const Angle &angle)const{
	Groupe* ret = new Groupe(_couleur);
	for(FormeGeom* f:composition){
        ret->ajouter(f->rotation(p,angle));
    }
	return ret;
}


void Groupe::ajouter(const FormeGeom* f){
	//TODO: v�rifier qu'il n'y est pas d�j�
	//TODO: changer le groupe si n�cessaire
    //TODO: verif que non null

}

void Groupe::supprimer(const FormeGeom* f){
	//TODO: verifier que la forme est bien dans ce groupe
	//TODO: v�rifier que pointeur non null
    //TODO:
    //	composition.push_back(f);

}

Groupe* Groupe::homothetie(const Point &p, const double scale)const{
	Groupe* g = new Groupe(*this);
	for(FormeGeom* f: g->composition){
        f->homothetie(p,scale);
    }
	return g;
}

Groupe* Groupe::translation(const Vecteur &v)const{
	Groupe* g = new Groupe(*this);
    for(FormeGeom* f: g->composition){
        f->translation(v);
    }
	return g;
}

void Groupe::dessin(const DessinManager &d) const{
    for(const FormeGeom* f : composition){
        f->dessin(d);
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

string Groupe::serialisation()const{
//TODO
}
