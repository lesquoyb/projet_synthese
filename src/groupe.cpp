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
    //TODO: tester
    if(f != NULL){
        if(f->appartientA() != this){
            if(f->appartientA() != NULL ){
                f->appartientA()->enlever(f);
            }
            f->setCouleur(_couleur);
            _composition.push_back(f);
        }
    }
}

/**
 * @brief Groupe::enlever
 * enlève forme du groupe, ne le supprime pas de la mémoire.
 * @param forme
 */
void Groupe::enlever(const FormeGeom* forme){
    //TODO: tester
    if (forme != NULL){
        if(forme->appartientA() == this){
         _composition.erase(find(_composition.begin(),_composition.end(),forme));
        }
    }
}


/**
 * @brief Groupe::supprimer
 * enlève la forme de la liste et de la mémoire.
 * @param f
 */
void Groupe::supprimer(const double &index){
    //TODO:tester
    if(index < _composition.size()){
         FormeGeom* temp = _composition[index];
         _composition.erase(_composition.begin()+index);
         delete temp;
    }

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


/**
 * @brief Groupe::~Groupe
 * Supprime tous les objets dans le groupe pour éviter les fuites mémoires qui peuvent être causée en faisant: "groupe.ajouter(new Segment(... , ... ));".
 */
Groupe::~Groupe(){
    //TODO:tester
    for(FormeGeom* f : _composition){
        delete f;
    }
}

string Groupe::toString()const{
    ostringstream ser;
    ser << "groupe( " << ';' << Couleurs::couleurToHexa(_couleur) << ";";
    for(FormeGeom* f : _composition){
        ser << f->toString() << "; ";
    }
    return ser.str() + ")";
}

ostream& operator<<(ostream &stream,const Groupe &g){
    stream << g.toString();
    return stream;
}















