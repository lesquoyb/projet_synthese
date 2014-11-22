#ifndef FACADE_H
#define FACADE_H
#include "expertcor.h"


template<class retour, class aTraiter>
class Facade {

protected:

    ExpertCOR<retour,aTraiter>* _first;

public:


    retour* run(aTraiter &objet){
        return _first->traitement(objet);
    }

};

#endif // FACADE_H
