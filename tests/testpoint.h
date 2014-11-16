#ifndef TESTPOINT_H
#define TESTPOINT_H
#include "test.h"
#include "../src/point.h"



CUNIT(TestPoint)

    Point origine(0,0);
    Point un(1,1);



    TESTCASE(translationSimple,{
        equals(origine.translation(Vecteur(2,3)), Point(2,3) );
     });

    TESTCASE(translationFausse,{
        nEquals(origine.translation(Vecteur(2,3)), Point(2,4) );
    });

    TESTCASE(rotationSimple,{
         equals(un.rotation(origine,Angle(90)).getCoordEntieres() , Point(-1,1));
    });

    TESTCASE(rotationFausse,{
         nEquals(un.rotation(origine,Angle(90)) , un);
    });

    TESTCASE(rotation360,{
        equals(un.rotation(origine,Angle(360)).getCoordEntieres(), un );
     });



ENDUNIT

#endif // TESTPOINT_H


void aire();
void rotationAngleNeg();
void rotation();
void rotationAngleSup2Pi();
void rotationZero();
void translationTrue();
void translationFalse();
void translationByZero();
void homothetieTrue();
void homothetieFalse();
void homothetieByZero();
