#ifndef TESTCOULEURS_H
#define TESTCOULEURS_H

#include "../exceptions/exceptioncouleurinexistante.h"
#include "cpptest.h"
#include "../src/Couleur.h"

CPPTEST(TestCouleurs)

        TESTCASE(CouleurToStringTestTrue,{
          equals(Couleurs::isCouleur("black") ,  true);
         });

        TESTCASE(CouleurToStringTestFalse, {
            equals(Couleurs::isCouleur("violet"), false);
        });

        TESTCASE(ExceptionCouleurInexistante,{
             errorExpected({
                 Segment s("violet",Point(1,0),Point(0,0));
             });
         });

ENDTEST

#endif // TESTCOULEURS_H
