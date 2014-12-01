#ifndef TESTCOULEURS_H
#define TESTCOULEURS_H

#include "../exceptions/exceptioncouleurinexistante.h"
#include "cpptest.h"
#include "../src/Couleur.h"

CPPTEST(TestCouleurs)

        TESTCASE(CouleurToStringTestTrue,{
          Equals(Couleurs::isCouleur("black") ,  true);
         });

        TESTCASE(CouleurToStringTestFalse, {
            Equals(Couleurs::isCouleur("violet"), false);
        });


ENDTEST

#endif // TESTCOULEURS_H
