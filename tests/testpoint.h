#ifndef TESTPOINT_H
#define TESTPOINT_H
#include "cpptest.h"
#include "../src/point.h"



CPPTEST(TestPoint)

    Point origine(0,0);
    Point un(1,1);
    Point rot90(-1,1);
    Vecteur vUn(1,1);

    TESTCASE(rotationSimple,{
         equals(un.rotation(origine,Angle(90))->toString() ,rot90.toString());
    });

    TESTCASE(rotationFausse,{
         nEquals(un.rotation(origine,Angle(90))->toString() , un.toString());
    });

    TESTCASE(rotation360,{
        equals(un.rotation(origine,Angle(360))->toString(), un.toString() );
     });

    TESTCASE(rotationAngleNeg,{
       equals(un.rotation(origine,Angle(-90))->toString() , Point(1,-1).toString());
     });

    TESTCASE(rotationSup360,{
        equals(un.rotation(origine,Angle(450))->toString(), rot90.toString());
     });

    TESTCASE(rotationZero, {
         equals(un.rotation(origine, Angle(0))->toString(), un.toString());
     });

    TESTCASE(translationSimple,{
         equals(origine.translation(vUn)->toString(), un.toString());
     });

    TESTCASE(translationFausse, {
         nEquals(origine.translation(vUn)->toString(), origine.toString());
     });

    TESTCASE(translationNeg, {
         equals(origine.translation(Vecteur(-1,-1))->toString(), Point(-1,-1).toString());
     });

    TESTCASE(translationZero, {
         equals(origine.translation(Vecteur(0,0))->toString(), origine.toString());
     });

    TESTCASE(homothetieSimple, {
         equals(un.homothetie(origine,0.5)->toString(), Point(0.5,0.5).toString());
     });

    TESTCASE(homothetieFausse, {
         nEquals(un.homothetie(origine, 0.5)->toString(), un.toString());
     });

    TESTCASE(homothetieScaleNeg,{
         equals(un.homothetie(origine, -1)->toString(), Point(-1,-1).toString());
     });

    TESTCASE(homothetieScaleUn,{
         equals(un.homothetie(origine, 1)->toString(), un.toString());
     });

    TESTCASE(homothetieSup1,{
         equals(un.homothetie(origine, 2)->toString(), Point(2,2).toString());
     });

    TESTCASE(homothetieSurOrigine, {
         equals(origine.homothetie(un,1)->toString(),origine.toString());
     });

    TESTCASE( homothetieZero,{
        equals(un.homothetie(origine,0)->toString(), origine.toString());
    });

ENDTEST

#endif // TESTPOINT_H
