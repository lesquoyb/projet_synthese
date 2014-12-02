#ifndef TESTSEGMENT_H
#define TESTSEGMENT_H
#include "../src/segment.h"
#include "cpptest.h"
#include <memory>

using std::unique_ptr;

/**
  *@brief TestSegment
  * La classe de tests sur les segments.
  */
CPPTEST(TestSegment)


    Point origine(0,0);
    Point pUn(1,1);
    Point pRot90(-1,1);
    Segment un(origine,pUn);


    TESTCASE(aire,{
        Equals(un.aire(),0);
    });

    TESTCASE(rotationSimple,{
        unique_ptr<Segment>s(un.rotation(origine,Angle(90)));
         Equals(s->toString() , Segment(origine,pRot90).toString());
     });

    TESTCASE(translationSimple,{
         unique_ptr<Segment>s(un.translation(Vecteur(origine,pUn)));
         Equals(s->toString(),Segment(pUn,Point(2,2)).toString());
     });

    TESTCASE(homothetieSimple, {
         unique_ptr<Segment>s(un.homothetie(origine,1));
         Equals(s->toString(), un.toString());
     });

    TESTCASE(toString,{
         Equals(un.toString(),"segment: #000000, 0, 0, 1, 1");
     });

ENDTEST

#endif // TESTSEGMENT_H

