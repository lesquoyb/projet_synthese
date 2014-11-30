#include "chargementgroupe.h"
#include "chargementfacade.h"
#include <algorithm>

Groupe* ChargementGroupe::traitementSpecialise(string &objet) const{
        string contenu = objet;
        string type = "groupe(";
        if(contenu.find(type) == 0){
            Groupe* g = new Groupe();
            contenu = trim(contenu);
            vector<string> valeurs = split(contenu,';');
            valeurs.erase(valeurs.begin());//on enlève le type
            valeurs.pop_back();//on enlève la parenthèse finale
             Couleurs::Couleur couleur = Couleurs::hexaToCouleur(trim(valeurs[0]));
             valeurs.erase(valeurs.begin()); // on enlève la couleur

             // s'il y a d'autres groupes dedans on relance le traitement:
             for(int i = 0 ; i < valeurs.size() ; i++ ){valeurs[i] = trim(valeurs[i]);} // on supprime les espaces inutiles
             vector<string>::iterator it;
             while((it = find(valeurs.begin(),valeurs.end(),"groupe(")) != valeurs.end() ){
                vector<string>::iterator end ,temp = it;
                while(( temp = find(temp+1,valeurs.end(),")")) != valeurs.end() ){
                    end = temp;
                }

                string g2;
                 for(vector<string>::iterator j = it; j <  end ; j ++){
                     g2 += *j + ";";
                 }
                 g2 += *end;
                 FormeGeom* f = ChargementFacade(g2).run();
                 g->ajouter(*f);
                 delete f;
                 valeurs.erase(it, end+1 );
            }
            for(string objet : valeurs){
                FormeGeom* f = ChargementFacade(objet).run();
                g->ajouter(*f);
                delete f;
            }
            return g;
        }

        return NULL;
    }
