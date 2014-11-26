#ifndef FORMECOMPOSEE_H
#define FORMECOMPOSEE_H
#include "formegeom.h"
#include <vector>

using std::vector;

template<class C,class T>
class FormeComposee : public FormeGeom {


protected:

    vector<C*> _composants;

public:

    vector<C*> getComposants()const{return _composants;}

    FormeComposee():FormeGeom(){}

    FormeComposee(const Couleurs::Couleur &couleur):FormeGeom(couleur){}


    virtual void dessin(const Dessinable &d) const{
        for_each(_composants.begin(),_composants.end(), [&d](C* f ) { f->dessin(d); } );
    }



    virtual FormeComposee<C,T>* rotation(const Point &p, const Angle &angle) const{
        //TODO: avec for_each
        T* ret = new T(_couleur);
        for(C* f: _composants){
            ret->ajouter(f->rotation(p,angle));
        }
        return ret;
    }

    virtual void ajouter( C* f){
        //TODO: tester
        if(f != NULL){
            if(f->appartientA() != this){
                if(f->appartientA() != NULL ){
                    f->appartientA()->enlever(f);
                }
                f->setCouleur(_couleur);
                _composants.push_back(f);
            }
        }
    }

};

#endif // FORMECOMPOSEE_H
