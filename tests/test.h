#ifndef TEST_H
#define TEST_H
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class Test{



public:

     string _name;
     vector<function<string()>> _functions;

    Test(){};
    vector<string> run(){
        vector<string> _errors;
        string temp;
        for(auto func : _functions){
            if((temp = func()) != "" ) _errors.push_back(temp);
        }

        return _errors;
    }

     string getName(){return _name;}


};

#endif // TEST_H
