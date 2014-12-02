#ifndef EXPERTCOR_H
#define EXPERTCOR_H
#include "expert.h"


template<class retour, class aTraiter>
/**
 * @brief The ExpertCOR class
 * Spécialisation de l'expert, l'expert COR est fait pour être utilisé dans une Chain Of Responsibility
 * C'est pourquoi il est doté d'un poiteur sur un autre ExpertCOR: le suivant dans la chaine.
 * De plus il définie sa fonction de traitement de façon à ce qu'elle renvoie le résultat du suivant si jamais l'expert est incapable de traiter les données.
 */
class ExpertCOR : public Expert<retour, aTraiter>{

private:

    ExpertCOR<retour,aTraiter>* suivant;

public:

    void ajouterSuivant(ExpertCOR<retour,aTraiter>* suiv){
        if( suivant == NULL ){
            suivant = suiv;
        }
        else{
            suivant->ajouterSuivant(suiv);
        }
    }

    virtual retour* traitement(aTraiter &objet)const{
            retour* ret = traitementSpecialise(objet);
            if( ret == NULL and suivant != NULL){
                return  suivant->traitement(objet);
            }
            return ret;
    }

    /**
     * @brief traitement1
     * Si pas de suivant et echec du traitement, lève l'exception traitement impossible
     * @param objet
     * @return
     */
    virtual retour* traitementSpecialise(aTraiter &objet) const = 0;

    virtual ~ExpertCOR(){
        delete suivant;
    }


};

#endif // EXPERTCOR_H
