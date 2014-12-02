#ifndef TESTPOINT_H
#define TESTPOINT_H
#include "cpptest.h"
#include "../src/point.h"
#include <memory>

using std::unique_ptr;

/**
  *@brief TestPoint
  * La classe de tests sur les points.
  */
CPPTEST(TestPoint)

    Point origine(0,0);
    Point un(1,1);
    Point rot90(-1,1);
    Vecteur vUn(1,1);

    TESTCASE(rotationSimple,{
         unique_ptr<Point> point(un.rotation(origine,Angle(90)));
         Equals(point->toString() ,rot90.toString());
    });

    TESTCASE(rotationFausse,{
        unique_ptr<Point> point (un.rotation(origine,Angle(90)));
        nEquals(point->toString() , un.toString());
    });

    TESTCASE(rotation360,{
                 unique_ptr<Point> point(un.rotation(origine,Angle(360)));
                 Equals(point->toString(), un.toString() );
     });

    TESTCASE(rotationAngleNeg,{
                 unique_ptr<Point> point (un.rotation(origine,Angle(-90)));
               Equals(point->toString() , Point(1,-1).toString());
             });

    TESTCASE(rotationSup360,{
                 unique_ptr<Point> point  (un.rotation(origine,Angle(450)));
                Equals(point->toString(), rot90.toString());
             });

    TESTCASE(rotationZero, {
                 unique_ptr<Point> point (un.rotation(origine, Angle(0)));
                 Equals(point->toString(), un.toString());
             });

    TESTCASE(translationSimple,{
                 unique_ptr<Point> point(origine.translation(vUn));
                 Equals(point->toString(), un.toString());
             });

    TESTCASE(translationFausse, {
                 unique_ptr<Point> point (origine.translation(vUn));
                 nEquals(point->toString(), origine.toString());
             });

    TESTCASE(translationNeg, {
                 unique_ptr<Point> point(origine.translation(Vecteur(-1,-1)));
                 Equals(point->toString(), Point(-1,-1).toString());
             });

    TESTCASE(translationZero, {
                 unique_ptr<Point> point(origine.translation(Vecteur(0,0)));
                 Equals(point->toString(), origine.toString());
             });

    TESTCASE(homothetieSimple, {
                 unique_ptr<Point> point (un.homothetie(origine,0.5));
                 Equals(point->toString(), Point(0.5,0.5).toString());
             });

    TESTCASE(homothetieFausse, {
                 unique_ptr<Point> point(un.homothetie(origine, 0.5));
                 nEquals(point->toString(), un.toString());
     });

    TESTCASE(homothetieScaleNeg,{
                 unique_ptr<Point> point(un.homothetie(origine, -1));
                 Equals(point->toString(), Point(-1,-1).toString());
     });

    TESTCASE(homothetieScaleUn,{
                 unique_ptr<Point> point (un.homothetie(origine, 1));
                 Equals(point->toString(), un.toString());
     });

    TESTCASE(homothetieSup1,{
                 unique_ptr<Point> point(un.homothetie(origine, 2));
         Equals(point->toString(), Point(2,2).toString());
     });

    TESTCASE(homothetieSurOrigine, {
                 unique_ptr<Point> point(origine.homothetie(un,1));
                 Equals(point->toString(),origine.toString());
     });

    TESTCASE( homothetieZero,{
                  unique_ptr<Point> point (un.homothetie(origine,0));
                  Equals(point->toString(), origine.toString());
    });

ENDTEST

#endif // TESTPOINT_H
