#ifndef GROUPE_H
#define GROUPE_H
#include "formegeom.h"
#include <vector>

class Groupe : public FormeGeom{

private:

    vector<FormeGeom*> composition;

public:

    Groupe(const string & coul);

	void ajouter(const FormeGeom*);
	void supprimer(const FormeGeom*);


    virtual Groupe* rotation(const Point &p,const Angle &angle)const;
    virtual Groupe* homothetie(const Point&,const double)const;
    virtual Groupe* translation(const Vecteur&)const;
    virtual void dessin()const;
    virtual double aire() const;
    virtual ~Groupe();


};

#endif // GROUPE_H
