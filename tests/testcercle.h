#ifndef TESTCERCLE_H
#define TESTCERCLE_H


#include "cpptest.h"
#include "../src/cercle.h"

CPPTEST(TestCercle)


    Point origine(0,0);
    Point pUn(1,1);
    Point pZeroUn(0,1);
    Point pRot90(-1,1);
    Point* temp = origine.rotation(pUn,Angle(90));
    Cercle* cTemp;
    Point unRot(*temp);
    delete temp;

    Cercle un(origine,5);


    TESTCASE(aire,{
        Equals(round(un.aire()*10)/10,78.5);
    });

    TESTCASE(rotationSimple,{
         cTemp = un.rotation(pUn,Angle(90));
         string stringUn = temp->toString();
         delete cTemp;
         Equals(stringUn , Cercle(unRot,un.getRayon()).toString());
     });

    TESTCASE(translationSimple,{
         cTemp = un.translation(Vecteur(origine,pUn));
         string stringUn = temp->toString();
         delete cTemp;
         Equals(stringUn,Cercle(pUn,un.getRayon()).toString());
     });

    TESTCASE(homothetieSimple, {
         Equals(un.homothetie(origine,2)->toString(), Cercle(origine, un.getRayon()*2).toString());
     });

    TESTCASE(toString,{
         Equals(un.toString(),"cercle: #000000, 0, 0, 5");
     });


ENDTEST

#endif // TESTCERCLE_H
