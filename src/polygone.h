#ifndef POLYGONE_H
#define POLYGONE_H
#include "formecomposee.h"
#include "point.h"
#include <vector>
#include <algorithm>


class Polygone : public FormeComposee<Point,Polygone> {

public:

    Polygone(const Couleurs::Couleur &couleur, const Point &p1, const Point &p2, const Point &p3);
    Polygone(const Point &p1,const Point &p2,const Point &p3);
    Polygone(const FormeComposee<Point,Polygone> &f);
    Polygone(const Polygone &p );


    /**
     * @brief ajouterPoint
     * @param p
     * Ajoute un point à la suite des précédents.
     * Le point est stocké sous forme du pointeur d'une copie du point passé en paramètres.
     */
    inline void ajouterPoint(const Point &p);

    virtual string toString()const;
    virtual double aire()const;


    virtual Polygone* clone()const;

    virtual void dessin(const Dessinable&)const ;



};


inline void Polygone::ajouterPoint(const Point &p){
    _composants.push_back(new Point(p));
}




#endif // POLYGONE_H
