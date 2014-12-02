#ifndef CHARGEMENTGROUPE_H
#define CHARGEMENTGROUPE_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "expertchargement.h"
#include "../groupe.h"

using namespace std;
/**
 * @brief The ChargementGroupe class
 * L'Expert en groupe.
 */
class ChargementGroupe : public ExpertChargement{


public:


    virtual Groupe* traitementSpecialise(string &objet) const;


};
#endif // CHARGEMENTGROUPE_H
