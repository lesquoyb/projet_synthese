#ifndef TESTFACADE_H
#define TESTFACADE_H
#include "test.h"
#include <vector>
#include "testcouleurs.h"
#include "testpoint.h"

class TestFacade{

private:

    vector<CUNIT*> _tests;

public:

    TestFacade(){

        _tests.push_back(new TestCouleurs());
        _tests.push_back(new TestPoint());
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
        for(CUNIT* t : _tests){
           cout << t->getName() << ": " << endl;
           int j = 0;
            for(string s : t->getRunResult()){
                cout << "# " << s << endl;
                if(s.find("ECHEC !") != string::npos) { //si on trouve echec dans la chaine
                    i++;
                    j++;
                }
            }
            ( j > 0 ) ? cout << "il y a "<< j <<" erreur(s)" : cout << "il n'y a pas d'erreur";
             cout << endl <<"============================="<< endl;
        }
        (i > 0 ) ? cout <<"il y a " << i <<" erreur(s)" : cout << "il n'y a pas d'erreur";
        cout << " dans l'ensemble des tests" << endl;
    }

    void addTest(CUNIT* t){
        _tests.push_back(t);
    }
};

#endif // TESTFACADE_H
