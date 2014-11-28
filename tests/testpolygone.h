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
        equals(round(p.aire()*10)/10,0.5);
    });


    TESTCASE(aireIrregulier,{
         equals(round(irregulier.aire()), 12);
     });


    TESTCASE(rotationSimple,{
        equals( *Polygone(*p.rotation(origine,Angle(90))).getCoordEntiere() , Polygone(origine,pRot90,Point(-1,0)));
    });

    TESTCASE(translationSimple,{
         equals(*p.translation(Vecteur(origine,pUn)),Polygone(pUn,Point(2,2),Point(1,2)));
     });

    TESTCASE(homothetieSimple, {
         equals(*p.homothetie(origine,1), p);
     });

    TESTCASE(toString,{
         equals(p.toString(),"polygone: #000000, 0, 0, 1, 1, 0, 1");
     });

ENDTEST



#endif // TESTPOLYGONE_H
