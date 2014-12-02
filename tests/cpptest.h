#ifndef TEST_H
#define TEST_H
#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "cpptesttools.h"







/**
 * @brief The CppTest class
 * Classe abstraite représentant un ensemble de tests unitaires.
 */
class CppTest{


protected:

    std::vector<std::function<bool()>> _functions;
    std::vector<std::string> _names;
    std::vector<std::string> _run;
    std::map<std::string,std::string> _debug;
    std::string _name;


public:

    /**
     * @brief run
     * Lance les tests unitaires de la classe.
     */
    void run(){
        for(unsigned int i = 0 ; i < _functions.size() ; i++){
            std::string detail;
            if(_functions[i]()) detail = "réussie";
            else detail ="ECHEC !"; //+ std::endl + _debug[_name[i]]; //TODO
            _run.push_back(_names[i] + " " + detail);
        }
    }

    /**
     * @brief getRunResult
     * @return le résultat des tests.
     */
    std::vector<std::string> getRunResult()const{return _run;}

    /**
      * @brief getName
      * @return le nom de l'ensemble de tests.
      */
     std::string getName()const{return _name;}



};

#endif // TEST_H
