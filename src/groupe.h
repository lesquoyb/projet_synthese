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


    virtual void ajouter(FormeGeom *f);


    void supprimer(const double &index);
    void enlever(const FormeGeom* forme);


    inline FormeGeom* get(size_t i)const ;

    virtual string toString()const;

    virtual void dessin(const Dessinable&d)const;
    virtual double aire() const;

    virtual Groupe* clone()const{return new Groupe(*this);}
    virtual ~Groupe();

};


/**
 * @brief get
 * @param i
 * @return l'objet à la position i, NULL si la position est mauvaise.
 * Attention ne pas détruire l'objet avant que le groupe ne soit lui même détruit.
 */
inline FormeGeom* Groupe::get(size_t i)const {
    if( i < _composants.size() ) {
        return _composants.at(i);
    }
    return NULL;
}

#endif // GROUPE_H
