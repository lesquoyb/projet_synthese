#ifndef DESSINABLE_H
#define DESSINABLE_H


class Cercle;
class Polygone;
class Segment;
class Triangle;

/**
 * @brief The Dessinable class
 * Il s'agit d'une interface décrivant le comportement que doit avoir les classes de dessin.
 * Cette classe sers donc majoritairement à assurer l'évolutivité de l'application en indiquant
 * aux autres classes voulant dessiner les formes géometriques quelles méthodes elles doivent implémenter.
 */
class Dessinable{


public:

    virtual void dessinerCercle(const Cercle &c)const = 0;
    virtual void dessinerTriangle(const Triangle &t)const = 0;
    virtual void dessinerSegment(const Segment &s)const = 0;
    virtual void dessinerPolygone(const Polygone &p)const = 0;

};

#endif // DESSINABLE_H
