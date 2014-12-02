#ifndef TESTCOULEURS_H
#define TESTCOULEURS_H

#include "cpptest.h"
#include "../src/Couleur.h"


/**
  *@brief TestCouleurs
  * La classe de tests sur les couleurs.
  */
CPPTEST(TestCouleurs)

        TESTCASE(CouleurToStringTestTrue,{
          Equals(Couleurs::isCouleur("black") ,  true);
         });

        TESTCASE(CouleurToStringTestFalse, {
            Equals(Couleurs::isCouleur("violet"), false);
        });


ENDTEST

#endif // TESTCOULEURS_H
