#ifndef TESTCERCLE_H
#define TESTCERCLE_H


#include "cpptest.h"
#include "../src/cercle.h"

CPPTEST(TestCercle)


    Vecteur origine(0,0);
    Vecteur pUn(1,1);
    Vecteur pZeroUn(0,1);
    Vecteur pRot90(-1,1);
    Cercle un(origine,5);


    TESTCASE(aire,{
        equals(round(un.aire()*10)/10,78.5);
    });

    TESTCASE(rotationSimple,{
         equals(*un.rotation(pUn,Angle(90))->getCoordEntiere() , Cercle(Vecteur(2,0),un.getRayon()));
     });

    TESTCASE(translationSimple,{
         equals(*un.translation(Vecteur(origine,pUn)),Cercle(pUn,un.getRayon()));
     });

    TESTCASE(homothetieSimple, {
         equals(*un.homothetie(origine,2), Cercle(origine, un.getRayon()*2));
     });

    TESTCASE(toString,{
         equals(un.toString(),"cercle: #000000, 0, 0, 5");
     });

ENDTEST

#endif // TESTCERCLE_H
