#ifndef TESTTRIANGLE_H
#define TESTTRIANGLE_H
#include "cpptest.h"
#include "../src/triangle.h"
#include <memory>

using std::unique_ptr;

/**
  *@brief TestTriangle
  * La classe de tests sur les triangles.
  */
CPPTEST(TestTriangle)


    Point origine(0,0);
    Point pUn(1,1);
    Point pZeroUn(0,1);
    Point pRot90(-1,1);
    Point* temp = pZeroUn.rotation(origine,Angle(90));
    Point p3Rot = *temp;
    delete temp;
    Triangle un(origine,pUn,pZeroUn);


    TESTCASE(aire,{
        Equals(round(un.aire()*10)/10,0.5);
    });

    TESTCASE(rotationSimple,{
         unique_ptr<Triangle> t(un.rotation(origine,Angle(90)));
         Equals(t->toString() , Triangle(origine,pRot90,p3Rot).toString());
     });

    TESTCASE(translationSimple,{
         unique_ptr<Triangle> t(un.translation(Vecteur(origine,pUn)));
         Equals(t->toString(),Triangle(pUn,Point(2,2),Point(1,2)).toString());
     });

    TESTCASE(homothetieSimple, {
         unique_ptr<Triangle> t(un.homothetie(origine,1));
         Equals(t->toString(), un.toString());
     });

    TESTCASE(toString,{
         Equals(un.toString(),"triangle: #000000, 0, 0, 1, 1, 0, 1");
     });


ENDTEST


#endif // TESTTRIANGLE_H
