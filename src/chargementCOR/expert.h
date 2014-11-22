#ifndef EXPERT_H
#define EXPERT_H

template<class retour,class aTraiter>
class Expert{


public:

    virtual retour* traitement(aTraiter &objet) const = 0;

};

#endif // EXPERT_H
