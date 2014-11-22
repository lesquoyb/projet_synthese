#ifndef TESTPOLYGONE_H
#define TESTPOLYGONE_H
#include "cpptest.h"
#include "../src/polygone.h"

CPPTEST(TestPolygone)


    Vecteur origine(0,0);
    Vecteur pUn(1,1);
    Vecteur pZeroUn(0,1);
    Vecteur pRot90(-1,1);
    Polygone p(origine,pUn,pZeroUn);
    Polygone irregulier(Vecteur(-1,2),Vecteur(7,5),Vecteur(4,3));
    irregulier.ajouterPoint(Vecteur(6,-1));
    irregulier.ajouterPoint(Vecteur(3,1));



    TESTCASE(aire,{
        equals(round(p.aire()*10)/10,0.5);
    });


    TESTCASE(aireIrregulier,{
         equals(round(irregulier.aire()), 12);
     });


    TESTCASE(rotationSimple,{
         equals(*p.rotation(origine,Angle(90))->getCoordEntiere() , Polygone(origine,pRot90,Vecteur(-1,0)));
     });

    TESTCASE(translationSimple,{
         equals(*p.translation(Vecteur(origine,pUn)),Polygone(pUn,Vecteur(2,2),Vecteur(1,2)));
     });

    TESTCASE(homothetieSimple, {
         equals(*p.homothetie(origine,1), p);
     });

    TESTCASE(toString,{
         equals(p.toString(),"polygone: #000000, 0, 0, 1, 1, 0, 1");
     });

ENDTEST



#endif // TESTPOLYGONE_H
