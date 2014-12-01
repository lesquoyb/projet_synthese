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
         Equals(un.rotation(origine,Angle(90))->toString() ,rot90.toString());
    });

    TESTCASE(rotationFausse,{
         nEquals(un.rotation(origine,Angle(90))->toString() , un.toString());
    });

    TESTCASE(rotation360,{
        Equals(un.rotation(origine,Angle(360))->toString(), un.toString() );
     });

    TESTCASE(rotationAngleNeg,{
       Equals(un.rotation(origine,Angle(-90))->toString() , Point(1,-1).toString());
     });

    TESTCASE(rotationSup360,{
        Equals(un.rotation(origine,Angle(450))->toString(), rot90.toString());
     });

    TESTCASE(rotationZero, {
         Equals(un.rotation(origine, Angle(0))->toString(), un.toString());
     });

    TESTCASE(translationSimple,{
         Equals(origine.translation(vUn)->toString(), un.toString());
     });

    TESTCASE(translationFausse, {
         nEquals(origine.translation(vUn)->toString(), origine.toString());
     });

    TESTCASE(translationNeg, {
         Equals(origine.translation(Vecteur(-1,-1))->toString(), Point(-1,-1).toString());
     });

    TESTCASE(translationZero, {
         Equals(origine.translation(Vecteur(0,0))->toString(), origine.toString());
     });

    TESTCASE(homothetieSimple, {
         Equals(un.homothetie(origine,0.5)->toString(), Point(0.5,0.5).toString());
     });

    TESTCASE(homothetieFausse, {
         nEquals(un.homothetie(origine, 0.5)->toString(), un.toString());
     });

    TESTCASE(homothetieScaleNeg,{
         Equals(un.homothetie(origine, -1)->toString(), Point(-1,-1).toString());
     });

    TESTCASE(homothetieScaleUn,{
         Equals(un.homothetie(origine, 1)->toString(), un.toString());
     });

    TESTCASE(homothetieSup1,{
         Equals(un.homothetie(origine, 2)->toString(), Point(2,2).toString());
     });

    TESTCASE(homothetieSurOrigine, {
         Equals(origine.homothetie(un,1)->toString(),origine.toString());
     });

    TESTCASE( homothetieZero,{
        Equals(un.homothetie(origine,0)->toString(), origine.toString());
    });

ENDTEST

#endif // TESTPOINT_H
