#ifndef TESTTRIANGLE_H
#define TESTTRIANGLE_H
#include "cpptest.h"
#include "../src/triangle.h"

CPPTEST(TestTriangle)


    Vecteur origine(0,0);
    Vecteur pUn(1,1);
    Vecteur pZeroUn(0,1);
    Vecteur pRot90(-1,1);
    Triangle un(origine,pUn,pZeroUn);


    TESTCASE(aire,{
        equals(round(un.aire()*10)/10,0.5);
    });

    TESTCASE(rotationSimple,{
         equals(*un.rotation(origine,Angle(90))->getCoordEntiere() , Triangle(origine,pRot90,Vecteur(-1,0)));
     });

    TESTCASE(translationSimple,{
         equals(*un.translation(Vecteur(origine,pUn)),Triangle(pUn,Vecteur(2,2),Vecteur(1,2)));
     });

    TESTCASE(homothetieSimple, {
         equals(*un.homothetie(origine,1), un);
     });

    TESTCASE(toString,{
         equals(un.toString(),"triangle: #000000, 0, 0, 1, 1, 0, 1");
     });

ENDTEST


#endif // TESTTRIANGLE_H
