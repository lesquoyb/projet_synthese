#include "groupe.h"
#include <functional>
#include <algorithm>


Groupe::Groupe(const string &coul): FormeGeom(coul){}

Groupe* Groupe::rotation(const Point &p, const Angle &angle)const{
    //TODO: avec for_each
	Groupe* ret = new Groupe(_couleur);
    for(FormeGeom* f:_composition){
        ret->ajouter(f->rotation(p,angle));
    }
	return ret;
}


void Groupe::ajouter(const FormeGeom* f){
	//TODO: vérifier qu'il n'y est pas déjà
	//TODO: changer le groupe si nécessaire
    //TODO: verif que non null

}

void Groupe::supprimer(const FormeGeom* f){
	//TODO: verifier que la forme est bien dans ce groupe
	//TODO: vérifier que pointeur non null
    //TODO:
    //	composition.push_back(f);

}

Groupe* Groupe::homothetie(const Point &p, const double scale)const{
    //TODO: test
	Groupe* g = new Groupe(*this);
    for(FormeGeom* f: g->_composition){
        f->homothetie(p,scale);
    }
	return g;
}

Groupe* Groupe::translation(const Vecteur &v)const{
    //TODO: test
	Groupe* g = new Groupe(*this);
    for(FormeGeom* f: g->_composition){
        f->translation(v);
    }
	return g;
}

void Groupe::dessin(const Dessinable &d) const{
    //TODO test
    //for_each(_composition.begin(),_composition.end(),[d](FormeGeom*f){f->dessin(d);});
    /*
    for(const FormeGeom* f : _composition){
        f->dessin(d);
    }
    */
}

double Groupe::aire() const{
    //TODO avec for_each
    double aire = 0;
    for(const FormeGeom* f : _composition){
        aire += f->aire();
    }
    return aire;
}

Groupe::~Groupe(){
    //TODO
}

string Groupe::serialisation()const{
//TODO 
	return "lol";
}
