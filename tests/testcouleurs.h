#ifndef TESTCOULEURS_H
#define TESTCOULEURS_H
#include "test.h"

class TestCouleurs : public Test{



public:

    TestCouleurs(){
        Test::_name = "TestCouleur";
        _functions.push_back(CouleurToStringTestFalse);
        _functions.push_back(CouleurToStringTestTrue);
    }


   static function<string()> CouleurToStringTestFalse;
    static function<string()> CouleurToStringTestTrue;
};

#endif // TESTCOULEURS_H
