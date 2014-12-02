#ifndef FACADE_H
#define FACADE_H
#include "expertcor.h"


template<class retour, class aTraiter>
/**
 * @brief The Facade class
 * Une façade faite pour rendre l'utilisation des ExpertCOR plus facile.
 */
class Facade {

protected:

    ExpertCOR<retour,aTraiter>* _first;
    aTraiter _objet;

public:


    retour* run(){
        return _first->traitement(_objet);
    }

    ~Facade(){
        delete _first;
    }

};

#endif // FACADE_H
