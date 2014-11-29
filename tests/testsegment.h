#ifndef TESTSEGMENT_H
#define TESTSEGMENT_H
#include "../src/segment.h"
#include "cpptest.h"

CPPTEST(TestSegment)


    Point origine(0,0);
    Point pUn(1,1);
    Point pRot90(-1,1);
    Segment un(origine,pUn);


    TESTCASE(aire,{
        equals(un.aire(),0);
    });

    TESTCASE(rotationSimple,{
         equals(un.rotation(origine,Angle(90))->toString() , Segment(origine,pRot90).toString());
     });

    TESTCASE(translationSimple,{
         equals(un.translation(Vecteur(origine,pUn))->toString(),Segment(pUn,Point(2,2)).toString());
     });

    TESTCASE(homothetieSimple, {
         equals(un.homothetie(origine,1)->toString(), un.toString());
     });

    TESTCASE(toString,{
         equals(un.toString(),"segment: #000000, 0, 0, 1, 1");
     });

ENDTEST

#endif // TESTSEGMENT_H

