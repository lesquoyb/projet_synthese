#ifndef TESTPOLYGONE_H
#define TESTPOLYGONE_H
#include "cpptest.h"
#include "../src/polygone.h"
#include <memory>

using std::unique_ptr;


/**
  *@brief TestPolygone
  * La classe de tests sur les polygones.
  */
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

    TESTCASE(aireCarre1X1,{
         Polygone carre(Point(-1,-1),Point(-1,-2),Point(-2,-2));
         carre.ajouterPoint(Point(-2,-1));
                 Equals(carre.aire(),1);
     });

    TESTCASE(aireIrregulier,{
         Equals(round(irregulier.aire()), 12);
     });


    TESTCASE(rotationSimple,{
        unique_ptr<ObjetGeom> poly(p.rotation(origine,Angle(90)));
        Point* tmp = pZeroUn.rotation(origine,Angle(90));
        Point temp = * tmp;
        delete tmp;
        Equals( poly->toString() , Polygone(origine,pRot90,temp).toString());
    });

    TESTCASE(translationSimple,{
                 unique_ptr<ObjetGeom> poly(p.translation(Vecteur(origine,pUn)));
                 Equals(poly->toString(),Polygone(pUn,Point(2,2),Point(1,2)).toString());
     });

    TESTCASE(homothetieSimple, {
                 unique_ptr<ObjetGeom> poly(p.homothetie(origine,1));
                 Equals(poly->toString(), p.toString());
     });

    TESTCASE(toString,{
         Equals(p.toString(),"polygone: #000000, 0, 0, 1, 1, 0, 1");
     });

ENDTEST



#endif // TESTPOLYGONE_H
