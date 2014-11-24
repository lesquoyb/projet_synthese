#ifndef CHARGEMENTGROUPE_H
#define CHARGEMENTGROUPE_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "expertchargement.h"
#include "../groupe.h"

using namespace std;

class ChargementGroupe : public ExpertChargement{


public:


    virtual Groupe* traitementSpecialise(string &objet) const;


};
#endif // CHARGEMENTGROUPE_H
