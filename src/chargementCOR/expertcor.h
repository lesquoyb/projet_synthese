#ifndef EXPERTCOR_H
#define EXPERTCOR_H
#include "expert.h"
#include "../../exceptions/exceptiontraitementimpossible.h"


template<class retour, class aTraiter>
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
        try{
            retour* ret = traitement1(objet);
            if( ret == NULL and suivant != NULL){
                return  suivant->traitement(objet);
            }
            return ret;
        }
        catch(ExceptionTraitementImpossible e){
            std::cout << e.what();
            return NULL;
        }

    }

    /**
     * @brief traitement1
     * Si pas de suivant et echec du traitement, lève l'exception traitement impossible
     * @param objet
     * @return
     */
    virtual retour* traitement1(aTraiter &objet) const = 0;


};

#endif // EXPERTCOR_H
