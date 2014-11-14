#ifndef TESTFACADE_H
#define TESTFACADE_H
#include "test.h"
#include <vector>
#include "testcouleurs.h"

class TestFacade{

private:

    vector<Test*> _tests;

public:

    TestFacade(){

        _tests.push_back(new TestCouleurs());
        //_tests.push_back(TestFormeGeom());
        //_tests.push_back(TestGroupe());
        //_tests.push_back(TestSegment());
        //_tests.push_back(TestTriangle());
        //_tests.push_back(TestCercle());
        //_tests.push_back(TestPolygone());
        //_tests.push_back(TestVecteur());
        //_tests.push_back(TestPoint());
        //_tests.push_back(TestAngle());
    }

    void run(){
        int i = 0;
        for(Test* t : _tests){
           cout << t->getName() << ": " << endl;
           vector<string> errors = t->run();
            for(string s : errors){
                cout << "# " << s << endl;
                i++;
            }
            ( errors.size() > 0 ) ? cout << "il y a "<< errors.size() <<" erreur(s)" : cout << "il n'y a pas d'erreur";
             cout <<"============================="<< endl;
        }
        (i > 0 ) ? cout <<"il y a " << i <<" erreur(s)" : cout << "il n'y a pas d'erreur";
        cout << "dans l'ensemble des tests" << endl;
    }
};

#endif // TESTFACADE_H
