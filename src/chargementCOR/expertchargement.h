#ifndef ExpertChargement_H
#define ExpertChargement_H
#include "expertcor.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include "../formegeom.h"
#include "../tools.h"

using namespace std;
using namespace tools;

/**
 * @brief The ExpertChargement class
 * Spécialisation d'un ExpertCOR.
 * Cette classe est chargé de parser une chaine de caractère pour la transformer en FormeGeom.
 * Il s'agit d'une classe abstraite.
 */
class ExpertChargement : public ExpertCOR<FormeGeom,string>{

public:



    /**
     * @brief traitement1
     * @param objet
     * @return l'objet parsé ou NULL si non trouvé.
     */
    virtual FormeGeom* traitementSpecialise(string &objet) const = 0;


};

#endif // ExpertChargement_H
