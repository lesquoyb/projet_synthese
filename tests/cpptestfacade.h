#ifndef TESTFACADE_H
#define TESTFACADE_H
#include "cpptest.h"
#include <vector>

#define TESTLAUNCHER(name) class name : public CppTestFacade { public: ~name(){for(CppTest* f : _tests){delete f;}} name(){
#define ENDLAUNCHER }};


/**
 * @brief The CppTestFacade class
 * Une façade pour les tests unitaires.
 * C'est une classe abstraite dont il faut hériter.
 */
class CppTestFacade{

protected:

    std::vector<CppTest*> _tests;

public:


    /**
     * @brief run
     * Lance tous les tests de la façade.
     */
    void run(){
        int i = 0;
        int total = 0;
        std::cout << std::endl;
        for(CppTest* t : _tests){
           std::cout << t->getName() << ": " << std::endl;
           int j = 0;
            for(std::string s : t->getRunResult()){
                std::cout << "# " << s << std::endl;
                if(s.find("ECHEC !") != std::string::npos) { //si on trouve echec dans la chaine
                    i++;
                    j++;
                }
                total++;
            }
            ( j > 0 ) ? std::cout << "il y a "<< j <<" erreur(s)" : std::cout << "il n'y a pas d'erreur";
             std::cout << std::endl <<"============================="<< std::endl;
        }
        std::cout << total << " tests effectués" << std::endl;
        (i > 0 ) ? std::cout <<"il y a " << i <<" erreur(s)" : std::cout << "il n'y a pas d'erreur";
        std::cout << " dans l'ensemble des tests" << std::endl;
    }

    /**
     * @brief addTest
     * @param t
     * Ajoute un ensemble de tests.
     */
    void addTest(CppTest* t){
        _tests.push_back(t);
    }
};

#endif // TESTFACADE_H
