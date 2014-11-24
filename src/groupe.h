#ifndef GROUPE_H
#define GROUPE_H
#include "formegeom.h"
#include <vector>

class Groupe : public FormeGeom {

private:

    vector<FormeGeom*> _composition;


public:

    Groupe(const Couleurs::Couleur &coul);
    Groupe(const Groupe &g);
    Groupe();

    void ajouter(FormeGeom *);
    void supprimer(const double &index);
    void enlever(const FormeGeom* forme);
    int getNbElem()const{return _composition.size();}
    FormeGeom* get(int i)const {return _composition.at(i);}

    virtual string toString()const;
    virtual Groupe* getCoordEntiere()const;
    virtual Groupe* rotation(const Vecteur &p,const Angle &angle)const;
    virtual Groupe* homothetie(const Vecteur&,const double)const;
    virtual Groupe* translation(const Vecteur&)const;
    virtual void dessin(const Dessinable&d)const;
    virtual double aire() const;

    virtual Groupe* clone()const{return new Groupe(*this);}
    virtual ~Groupe();

    friend ostream& operator<<(ostream&,const Groupe &g);



};

#endif // GROUPE_H
