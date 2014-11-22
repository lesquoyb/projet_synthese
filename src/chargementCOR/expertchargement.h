#ifndef ExpertChargement_H
#define ExpertChargement_H
#include "expertcor.h"
#include "../segment.h"
#include <istream>

using std::ifstream;
using std::string;
using std::vector;

class ExpertChargement : public ExpertCOR<FormeGeom,ifstream>{

protected:

    const string lireFichier(ifstream &fichier)const{
        string str;
        ostringstream oss;
        while( getline( fichier, str ) ){
            oss << str;
        }
        return trim(oss.str());
    }

    vector<string> split(const string &s, char delim) const{
        vector<string> elems;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }

    const string trim(const string &s)const{
        int i, j;
        for(i = 0 ; i < s.size() and s[i] == ' '  ; i++){}
        for(j = s.size()-1 ; j > 0 and s[j] == ' '; j++ ){}
        return s.substr(i,j);
    }

public:

    virtual FormeGeom* chargement(ifstream &objet) const = 0;


    /**
     * @brief traitement1
     * @param objet
     * @return l'objet parsé ou NULL si non trouvé.
     */
    virtual FormeGeom* traitement1(ifstream &objet) const{

        if(objet.is_open() == false){
            throw ExceptionTraitementImpossible("fichier fermé");
        }
        return chargement(objet);
    }


};

#endif // ExpertChargement_H
