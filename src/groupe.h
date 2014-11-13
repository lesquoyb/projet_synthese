#ifndef GROUPE_H
#define GROUPE_H
#include "formegeom.h"
#include <vector>

class Groupe : public FormeGeom{

private:

    vector<FormeGeom*> _composition;

public:

    Groupe(const string & coul);

	void ajouter(const FormeGeom*);
	void supprimer(const FormeGeom*);

    virtual string serialisation()const;
    virtual Groupe* rotation(const Point &p,const Angle &angle)const;
    virtual Groupe* homothetie(const Point&,const double)const;
    virtual Groupe* translation(const Vecteur&)const;
    virtual void dessin(const Dessinable&d)const;
    virtual double aire() const;
    virtual ~Groupe();


};

#endif // GROUPE_H
