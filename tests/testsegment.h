#ifndef TESTSEGMENT_H
#define TESTSEGMENT_H
#include "../src/segment.h"
#include "cpptest.h"

CPPTEST(TestSegment)


    Vecteur origine(0,0);
    Vecteur pUn(1,1);
    Vecteur pRot90(-1,1);
    Segment un(origine,pUn);


    TESTCASE(aire,{
        equals(un.aire(),0);
    });

    TESTCASE(rotationSimple,{
         equals(*un.rotation(origine,Angle(90))->getCoordEntiere() , Segment(origine,pRot90));
     });

    TESTCASE(translationSimple,{
         //equals(*un.translation(Vecteur(origine,pUn)),Segment(pUn,Point(2,2)));
                 return true;
     });

    TESTCASE(homothetieSimple, {
         equals(*un.homothetie(origine,1), un);
     });

    TESTCASE(toString,{
         equals(un.toString(),"segment: #000000, 0, 0, 1, 1");
     });

ENDTEST

#endif // TESTSEGMENT_H

