#ifndef TESTPOINT_H
#define TESTPOINT_H
#include "cpptest.h"
#include "../src/point.h"



CPPTEST(TestPoint)

    Vecteur origine(0,0);
    Vecteur un(1,1);
    Vecteur rot90(-1,1);
    Vecteur vUn(1,1);

/*
    TESTCASE(rotationSimple,{
         equals(un.rotation(origine,Angle(90)).getCoordEntieres() ,rot90);
    });

    TESTCASE(rotationFausse,{
         nEquals(un.rotation(origine,Angle(90)) , un);
    });

    TESTCASE(rotation360,{
        equals(un.rotation(origine,Angle(360)).getCoordEntieres(), un );
     });

    TESTCASE(rotationAngleNeg,{
       equals(un.rotation(origine,Angle(-90)).getCoordEntieres() , Point(1,-1));
     });

    TESTCASE(rotationSup360,{
        equals(un.rotation(origine,Angle(450)).getCoordEntieres(), rot90);
     });

    TESTCASE(rotationZero, {
         equals(un.rotation(origine, Angle(0)).getCoordEntieres(), un);
     });

    TESTCASE(translationSimple,{
         equals(origine.translation(vUn), un);
     });

    TESTCASE(translationFausse, {
         nEquals(origine.translation(vUn), origine);
     });

    TESTCASE(translationNeg, {
         equals(origine.translation(Vecteur(-1,-1)), Point(-1,-1));
     });

    TESTCASE(translationZero, {
         equals(origine.translation(Vecteur(0,0)), origine);
     });

    TESTCASE(homothetieSimple, {
         equals(un.homothetie(origine,0.5), Point(0.5,0.5));
     });

    TESTCASE(homothetieFausse, {
         nEquals(un.homothetie(origine, 0.5), un);
     });

    TESTCASE(homothetieScaleNeg,{
         equals(un.homothetie(origine, -1), Point(-1,-1));
     });

    TESTCASE(homothetieScaleUn,{
         equals(un.homothetie(origine, 1), un);
     });

    TESTCASE(homothetieSup1,{
         equals(un.homothetie(origine, 2), Point(2,2));
     });

    TESTCASE(homothetieSurOrigine, {
         equals(origine.homothetie(un,1),origine);
     });

    TESTCASE( homothetieZero,{
        equals(un.homothetie(origine,0), origine);
    });

*/
ENDTEST

#endif // TESTPOINT_H
