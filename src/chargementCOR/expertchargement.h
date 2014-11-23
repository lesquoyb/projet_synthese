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

class ExpertChargement : public ExpertCOR<FormeGeom,string>{

public:

    virtual FormeGeom* chargement(string &objet) const = 0;


    /**
     * @brief traitement1
     * @param objet
     * @return l'objet parsé ou NULL si non trouvé.
     */
    virtual FormeGeom* traitement1(string &objet) const{

        return chargement(objet);
    }


};

#endif // ExpertChargement_H
