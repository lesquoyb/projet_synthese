#ifndef TESTVECTEUR_H
#define TESTVECTEUR_H
#include "cpptest.h"
#include "../src/vecteur.h"


/**
  *@brief TestVecteur
  * La classe de tests sur les vecteurs.
  */
CPPTEST(TestVecteur)


    Vecteur vUn(1,1);
    Vecteur vZero(0,0);


    TESTCASE(multi1,{
         Equals(1*vUn, vUn);
     });

    TESTCASE(multi0,{
         Equals(0*vUn,vZero);
     });

    TESTCASE(constructeurPoints,{
         Equals(vUn,Vecteur(Vecteur(0,0),Vecteur(1,1)));
     });

    TESTCASE(produitScalaire,{
         Equals(Vecteur(5,-2) * Vecteur(7,-6), 47);
     });

    TESTCASE(norme,{
         Equals(round(Vecteur(-2,5).norme()*100)/100,5.39);
     });


ENDTEST


#endif // TESTVECTEUR_H
