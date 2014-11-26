#ifndef TEST_H
#define TEST_H
#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "cpptesttools.h"








class CppTest{


protected:

    std::vector<std::function<bool()>> _functions;
    std::vector<std::string> _names;
    std::vector<std::string> _run;
    std::map<std::string,std::string> _debug;
    std::string _name;


public:

    void run(){
        for(unsigned int i = 0 ; i < _functions.size() ; i++){
            std::string detail;
            if(_functions[i]()) detail = "réussie";
            else detail ="ECHEC !"; //+ std::endl + _debug[_name[i]]; //TODO
            _run.push_back(_names[i] + " " + detail);
        }
    }
    std::vector<std::string> getRunResult()const{return _run;}
     std::string getName()const{return _name;}



};

#endif // TEST_H
