#ifndef TEST_H
#define TEST_H
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include "../src/formegeom.h"
#include "cunittools.h"






using namespace std;

class CUNIT{


protected:

    vector<function<bool()>> _functions;
    vector<string> _names;
    vector<string> _run;
    string _name;


public:

    void run(){
        for(int i = 0 ; i < _functions.size() ; i++){
            string detail;
            if(_functions[i]()) detail = "réussie";
            else detail ="ECHEC !";
            _run.push_back(_names[i] + " " + detail);
        }
    }
    vector<string> getRunResult()const{return _run;}
     string getName()const{return _name;}



};

#endif // TEST_H
