#ifndef FACADE_H
#define FACADE_H
#include "expertcor.h"


template<class retour, class aTraiter>
class Facade {

protected:

    ExpertCOR<retour,aTraiter>* _first;
    aTraiter _objet;

public:


    retour* run(){
        return _first->traitement(_objet);
    }

};

#endif // FACADE_H
