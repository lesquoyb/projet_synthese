#ifndef TESTTRIANGLE_H
#define TESTTRIANGLE_H
#include "cpptest.h"
#include "../src/triangle.h"

CPPTEST(TestTriangle)


    Point origine(0,0);
    Point pUn(1,1);
    Point pZeroUn(0,1);
    Point pRot90(-1,1);
    Point p3Rot = *pZeroUn.rotation(origine,Angle(90));
    Triangle un(origine,pUn,pZeroUn);


    TESTCASE(aire,{
        equals(round(un.aire()*10)/10,0.5);
    });

    TESTCASE(rotationSimple,{
         equals(un.rotation(origine,Angle(90))->toString() , Triangle(origine,pRot90,p3Rot).toString());
     });

    TESTCASE(translationSimple,{
         equals(un.translation(Vecteur(origine,pUn))->toString(),Triangle(pUn,Point(2,2),Point(1,2)).toString());
     });

    TESTCASE(homothetieSimple, {
         equals(un.homothetie(origine,1)->toString(), un.toString());
     });

    TESTCASE(toString,{
         equals(un.toString(),"triangle: #000000, 0, 0, 1, 1, 0, 1");
     });

ENDTEST


#endif // TESTTRIANGLE_H
