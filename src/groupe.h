#ifndef GROUPE_H
#define GROUPE_H
#include "formegeom.h"
#include <vector>

class Groupe : public FormeGeom{

private:

    vector<FormeGeom*> composition;
    Groupe();

public:

    Groupe(const string & coul);
    virtual void rotation(const Point &p,const Angle &angle);
    virtual void homothetie(const Point&,const double);
    virtual void translation(const Vecteur&);
    virtual void dessin()const;
    virtual double aire() const;
    virtual ~Groupe();


};

#endif // GROUPE_H
