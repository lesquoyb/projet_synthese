#ifndef TESTPOLYGONE_H
#define TESTPOLYGONE_H
#include "cpptest.h"
#include "../src/polygone.h"

CPPTEST(TestPolygone)

    Point origine(0,0);
    Point pUn(1,1);
    Point pZeroUn(0,1);
    Point pRot90(-1,1);
    Polygone p(origine,pUn,pZeroUn);
    Polygone irregulier(Point(-1,2),Point(7,5),Point(4,3));
    irregulier.ajouterPoint(Point(6,-1));
    irregulier.ajouterPoint(Point(3,1));



    TESTCASE(aire,{
        Equals(round(p.aire()*10)/10,0.5);
    });


    TESTCASE(aireIrregulier,{
         Equals(round(irregulier.aire()), 12);
     });


    TESTCASE(rotationSimple,{
        Equals( Polygone(*p.rotation(origine,Angle(90))).toString() , Polygone(origine,pRot90,*pZeroUn.rotation(origine,Angle(90))).toString());
    });

    TESTCASE(translationSimple,{
         Equals(Polygone(*p.translation(Vecteur(origine,pUn))).toString(),Polygone(pUn,Point(2,2),Point(1,2)).toString());
     });

    TESTCASE(homothetieSimple, {
         Equals(Polygone(*p.homothetie(origine,1)).toString(), p.toString());
     });

    TESTCASE(toString,{
         Equals(p.toString(),"polygone: #000000, 0, 0, 1, 1, 0, 1");
     });

ENDTEST



#endif // TESTPOLYGONE_H
