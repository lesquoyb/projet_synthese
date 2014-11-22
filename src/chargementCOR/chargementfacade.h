#ifndef CHARGEMENTFACADE_H
#define CHARGEMENTFACADE_H
#include "chargementsegment.h"
#include "facade.h"

class chargementFacade : public Facade<FormeGeom,ifstream>{



public:

    chargementFacade(){
        _first = new ChargementSegment();
    }

};

#endif // CHARGEMENTFACADE_H
