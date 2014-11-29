#ifndef POLYGONE_H
#define POLYGONE_H
#include "formecomposee.h"
#include "point.h"
#include <vector>
#include <algorithm>

/**
 * @brief The Polygone class
 * Cette classe représente un poygone, c'est à dire une ensemble de points dans un ordre donné.
 * Un polygone contient au moins trois points.
 * Les points stockés dans un polygone sont des copies des points envoyés.
 * L'ordre dans lequel on ajoute les points correspond à l'ordre dans lequel ils seront reliés: si on insère un point dans un polygone, il sera relié à au dernier point inséré et au premier de la liste.
 */
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
    inline void supprimerDernier();
    /**
     * @brief get
     * @param i
     * @return Une copie du point à la position demandée, ou NULL si i est incorrect.
     */
    inline Point* get(size_t i)const;

    //méthodes à implémenter
    virtual string toString()const;
    virtual double aire()const;
    virtual Polygone* clone()const;
    virtual void dessin(const Dessinable&)const ;

    virtual ~Polygone();

};


inline void Polygone::ajouterPoint(const Point &p){
    _composants.push_back(new Point(p));
}

inline void Polygone::supprimerDernier(){
    //TODO créer un test
    delete _composants.back();
    _composants.pop_back();
}

inline Point* Polygone::get(size_t i)const{
    //TODO: tester
    if(_composants.size() < i){
        return new Point(*_composants.at(i));
    }
    return NULL;
}


#endif // POLYGONE_H
