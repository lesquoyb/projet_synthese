#ifndef EXPERT_H
#define EXPERT_H

template<class retour,class aTraiter>
/**
 * @brief The Expert class
 * La classe décrivant le comportement d'un expert quelconque: il fait un traitement sur un objet, et a un retour.
 */
class Expert{


public:

    virtual retour* traitement(aTraiter &objet) const = 0;

};

#endif // EXPERT_H
