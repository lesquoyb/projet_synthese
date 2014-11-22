#include "groupe.h"
#include <functional>
#include <algorithm>


Groupe::Groupe(const Couleurs::Couleur &coul): FormeGeom(coul){}
Groupe::Groupe():FormeGeom(){}

Groupe* Groupe::rotation(const Vecteur &p, const Angle &angle)const{
    //TODO: avec for_each
	Groupe* ret = new Groupe(_couleur);
    for(FormeGeom* f:_composition){
        ret->ajouter(f->rotation(p,angle));
    }
	return ret;
}


void Groupe::ajouter( FormeGeom* f){
	//TODO: vérifier qu'il n'y est pas déjà
	//TODO: changer le groupe si nécessaire
    //TODO: changer la couleur
    //TODO: verif que non null
    _composition.push_back(f);

}

void Groupe::supprimer(const FormeGeom* f){
	//TODO: verifier que la forme est bien dans ce groupe
	//TODO: vérifier que pointeur non null
    //TODO:


}

Groupe* Groupe::homothetie(const Vecteur &p, const double scale)const{
    //TODO: test
    Groupe* ret = new Groupe(_couleur);
    for(FormeGeom* f:_composition){
        ret->ajouter(f->homothetie(p,scale));
    }
    return ret;
}

Groupe* Groupe::translation(const Vecteur &v)const{
    //TODO: test
    Groupe* ret = new Groupe(_couleur);
    for(FormeGeom* f:_composition){
        ret->ajouter(f->translation(v));
    }
    return ret;
}

void Groupe::dessin(const Dessinable &d) const{
    for_each(_composition.begin(),_composition.end(), [&d](FormeGeom* f ) { f->dessin(d); } );
}

Groupe* Groupe::getCoordEntiere()const{
    //TODO
    return new Groupe(*this);
}

double Groupe::aire() const{
    double aire = 0;
    for_each(_composition.begin(),_composition.end(), [&aire](FormeGeom* f ) { aire += f->aire(); } );
    return aire;
}

Groupe::Groupe(const Groupe &g):
FormeGeom(g._couleur)
{
    for(FormeGeom* f: g._composition){
        _composition.push_back(f->clone());
    }
}



Groupe::~Groupe(){
    //TODO
}

string Groupe::toString()const{
    ostringstream ser;
    ser << "polygone: " << Couleurs::couleurToHexa(_couleur) << ", ";
    for(FormeGeom* f : _composition){
        ser << f->toString() << "; ";
    }
    return ser.str().substr(0,ser.str().length()- 2); // on enlève 2 car c'est la taille du dernier "; "
}

ostream& operator<<(ostream &stream,const Groupe &g){
    stream << g.toString();
    return stream;
}















