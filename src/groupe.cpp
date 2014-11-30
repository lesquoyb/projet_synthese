#include "groupe.h"
#include <functional>
#include <algorithm>


Groupe::Groupe(const Couleurs::Couleur &coul): FormeComposee<FormeGeom,Groupe>(coul){}
Groupe::Groupe(const FormeComposee<FormeGeom,Groupe> &f):
    FormeComposee<FormeGeom,Groupe>(f.getCouleur())
{
    for (size_t i = 0; i < f.getComposants().size(); ++i){
        _composants.push_back(f.getComposants()[i]);
     }
}
Groupe::Groupe():FormeComposee<FormeGeom,Groupe>(){}



void Groupe::ajouter(const FormeGeom &f){
        //TODO: tester
        //if(f != NULL){
            FormeGeom* temp = f.clone();
            temp->setCouleur(_couleur);
            _composants.push_back(temp);
           /* if(f->appartientA() != this){
                if(f->appartientA() != NULL ){
                    f->appartientA()->enlever(f);
                }
                f->setAppartientA(this);

                f->setCouleur(_couleur);
                _composants.push_back(f->clone());
                                */
           // }
        //}
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



double Groupe::aire() const{
    double aire = 0;
    for_each(_composants.begin(),_composants.end(), [&aire](FormeGeom* f ) { aire += f->aire(); } );
    return aire;
}




Groupe::Groupe(const Groupe &g):
    FormeComposee<FormeGeom,Groupe>(g._couleur)
    {}


void Groupe::dessin(const Dessinable &d) const{
    for_each(_composants.begin(),_composants.end(),[&d](FormeGeom* f) {f->dessin(d);});
}





/**
 * @brief Groupe::~Groupe
 * Rien à faire car les objets dans le groupe doivent être gérés en dehors de celui-ci.
 */
Groupe::~Groupe(){
    for(FormeGeom* f : _composants){
        delete f;
    }
}

string Groupe::toString()const{
    ostringstream ser;
    ser << "groupe( " << ';' << Couleurs::couleurToHexa(_couleur) << ";";
    for(FormeGeom* f : _composants){
        ser << f->toString() << "; ";
    }
    return ser.str() + ")";
}
























