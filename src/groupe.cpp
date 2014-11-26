#include "groupe.h"
#include <functional>
#include <algorithm>


Groupe::Groupe(const Couleurs::Couleur &coul): FormeComposee<FormeGeom,Groupe>(coul){}
Groupe::Groupe():FormeComposee<FormeGeom,Groupe>(){}


/*
Groupe* Groupe::rotation(const Point &p, const Angle &angle)const{
    //TODO: avec for_each
	Groupe* ret = new Groupe(_couleur);
    for(FormeGeom* f:_composition){
        ret->ajouter(f->rotation(p,angle));
    }
	return ret;
}
*/

/*
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

*/

/**
 * @brief Groupe::enlever
 * enlève forme du groupe, ne le supprime pas de la mémoire.
 * @param forme
 */
void Groupe::enlever(const FormeGeom* forme){
    //TODO: tester
    if (forme != NULL){
        if(forme->appartientA() == this){
         _composants.erase(find(_composants.begin(),_composants.end(),forme));
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
    if(index < _composants.size()){
         FormeGeom* temp = _composants[index];
         _composants.erase(_composants.begin()+index);
         delete temp;
    }

}

Groupe* Groupe::homothetie(const Point &p, const double scale)const{
    //TODO: test
    Groupe* ret = new Groupe(_couleur);
    for(FormeGeom* f:_composants){
        ret->ajouter(f->homothetie(p,scale));
    }
    return ret;
}


Groupe* Groupe::translation(const Vecteur &v)const{
    //TODO: test
    Groupe* ret = new Groupe(_couleur);
    for(FormeGeom* f:_composants){
        ret->ajouter(f->translation(v));
    }
    return ret;
}




Groupe* Groupe::getCoordEntiere()const{
    //TODO
    return new Groupe(*this);
}

double Groupe::aire() const{
    double aire = 0;
    for_each(_composants.begin(),_composants.end(), [&aire](FormeGeom* f ) { aire += f->aire(); } );
    return aire;
}

Groupe::Groupe(const FormeComposee<FormeGeom, Groupe> &g):
FormeComposee<FormeGeom,Groupe>(g.getCouleur())
{
    for(FormeGeom* f: g.getComposants()){
        _composants.push_back(f->clone());
    }
}
/*
Groupe::Groupe(const FormeComposee<FormeGeom, Groupe> &g):
FormeComposee<FormeGeom,Groupe>(g._couleur)
{
    for(FormeGeom* f: g._composition){
        _composition.push_back(f->clone());
    }
}
*/

/**
 * @brief Groupe::~Groupe
 * Supprime tous les objets dans le groupe pour éviter les fuites mémoires qui peuvent être causée en faisant: "groupe.ajouter(new Segment(... , ... ));".
 */
Groupe::~Groupe(){
    //TODO:tester
    /*
    for(FormeGeom* f : _composition){
        delete f;
    }
    */
}

string Groupe::toString()const{
    ostringstream ser;
    ser << "groupe( " << ';' << Couleurs::couleurToHexa(_couleur) << ";";
    for(FormeGeom* f : _composants){
        ser << f->toString() << "; ";
    }
    return ser.str() + ")";
}

ostream& operator<<(ostream &stream,const Groupe &g){
    stream << g.toString();
    return stream;
}























