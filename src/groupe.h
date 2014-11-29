#ifndef GROUPE_H
#define GROUPE_H
#include "formecomposee.h"
#include <vector>

class Groupe : public  FormeComposee<FormeGeom,Groupe>{


public:

    Groupe(const FormeComposee<FormeGeom,Groupe> &f);
    Groupe(const Groupe &);
    Groupe(const Couleurs::Couleur &coul);
    Groupe();

    vector<FormeGeom*> getComposants()const {return _composants;}

    virtual void ajouter(FormeGeom *f){
        //TODO: tester
        if(f != NULL){
            if(f->appartientA() != this){
                if(f->appartientA() != NULL ){
                    f->appartientA()->enlever(f);
                }
                f->setAppartientA(this);
                f->setCouleur(_couleur);
                _composants.push_back(f);
            }
        }
    }


    void supprimer(const double &index);
    void enlever(const FormeGeom* forme);



    int getNbElem()const{return _composants.size();}
    FormeGeom* get(int i)const {return _composants.at(i);}

    virtual string toString()const;
    virtual Groupe* getCoordEntiere()const;

    virtual void dessin(const Dessinable&d)const;
    virtual double aire() const;

    virtual Groupe* clone()const{return new Groupe(*this);}
    virtual ~Groupe();

};

#endif // GROUPE_H
