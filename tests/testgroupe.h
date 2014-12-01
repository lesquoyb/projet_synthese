#ifndef TESTGROUPE_H
#define TESTGROUPE_H
#include "cpptest.h"
#include "../src/groupe.h"
#include "../src/segment.h"
#include "../src/triangle.h"
#include "../src/cercle.h"
#include <assert.h>


CPPTEST(TestGroupe)

        Point origine(0,0);
        Segment seg(Point(1,2),Point(2,2));
        Triangle tri(Point(1,2),Point(2,2),origine);
        Cercle cer(origine,10);
        Angle droit(-90);
        Vecteur vUn(1,1);
        Groupe g;
        g.ajouter(seg);
        g.ajouter(tri);
        g.ajouter(cer);




    TESTCASE(aire,{
        Equals(g.aire(),tri.aire()+cer.aire());
        return true;
    });

    TESTCASE ( rotation,{
         Groupe g2(*g.rotation(origine,droit));
         assert( (g2.get(0)->toString() == seg.rotation(origine,droit)->toString())  &&  (g2.get(1)->toString() == tri.rotation(origine,droit)->toString()) && (g2.get(2)->toString() == cer.rotation(origine,droit)->toString()) );
         return true;
    });


    TESTCASE(translation,{
        Groupe g2(*g.translation(vUn));
        assert(g2.get(0)->toString() == seg.translation(vUn)->toString());
        assert(g2.get(1)->toString() == tri.translation(vUn)->toString());
        assert(g2.get(2)->toString() == cer.translation(vUn)->toString());
        return true;
    });

    TESTCASE(homothetie,{
        Groupe g2(*g.homothetie(origine,2));
        assert( (g2.get(0)->toString() == g.get(0)->homothetie(origine,2)->toString()));
        assert(g2.get(1)->toString() == g.get(1)->homothetie(origine,2)->toString() ) ;
        assert(g2.get(2)->toString() == g.get(2)->homothetie(origine,2)->toString()) ;
        return true;
     });



ENDTEST

#endif // TESTGROUPE_H
