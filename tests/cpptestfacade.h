#ifndef TESTFACADE_H
#define TESTFACADE_H
#include "cpptest.h"
#include <vector>

#define TESTLAUNCHER(name) class name : public CppTestFacade { public:name(){
#define ENDLAUNCHER }};

class CppTestFacade{

private:

    std::vector<CppTest*> _tests;

public:

    void run(){
        int i = 0;
        for(CppTest* t : _tests){
           std::cout << t->getName() << ": " << std::endl;
           int j = 0;
            for(std::string s : t->getRunResult()){
                std::cout << "# " << s << std::endl;
                if(s.find("ECHEC !") != std::string::npos) { //si on trouve echec dans la chaine
                    i++;
                    j++;
                }
            }
            ( j > 0 ) ? std::cout << "il y a "<< j <<" erreur(s)" : std::cout << "il n'y a pas d'erreur";
             std::cout << std::endl <<"============================="<< std::endl;
        }
        (i > 0 ) ? std::cout <<"il y a " << i <<" erreur(s)" : std::cout << "il n'y a pas d'erreur";
        std::cout << " dans l'ensemble des tests" << std::endl;
    }

    void addTest(CppTest* t){
        _tests.push_back(t);
    }


};

#endif // TESTFACADE_H
