#ifndef DESSINMANAGER_H
#define DESSINMANAGER_H

#include "connexion.h"
#include "dessinable.h"


/**
 * @brief The DessinManager class
 * Cette classe est chargé de dessiner les formes géometriques.
 * Le dessin est fait en envoyant les formes géometriques à un serveur distant afin que celui-ci dessine.
 */
class DessinManager : public Dessinable{


private:

	Connexion* _connexion;

public:

    DessinManager(Connexion* c);
    virtual ~DessinManager(){}

    void dessinerCercle(const Cercle &c)const;
    void dessinerTriangle(const Triangle &t)const;
    void dessinerSegment(const Segment &s)const;
    void dessinerPolygone(const Polygone &p)const;

};

#endif
