#ifndef TESTGROUPE_H
#define TESTGROUPE_H
#include "cpptest.h"
#include "../src/groupe.h"
#include "../src/segment.h"
#include "../src/triangle.h"
#include "../src/cercle.h"
#include <assert.h>


CPPTEST(TestGroupe)

        Vecteur origine(0,0);
        Segment seg(Vecteur(1,2),Vecteur(2,2));
        Triangle tri(Vecteur(1,2),Vecteur(2,2),origine);
        Cercle cer(origine,10);
        Angle droit(-90);
        Vecteur vUn(1,1);
        Groupe g;
        g.ajouter(&seg);
        g.ajouter(&tri);
        g.ajouter(&cer);




    TESTCASE(aire,{
        equals(g.aire(),tri.aire()+cer.aire());
    });

    TESTCASE ( rotation,{
         Groupe g2(*g.rotation(origine,droit));
         assert( (g2.get(0)->toString() == seg.rotation(origine,droit)->toString())  &&  (g2.get(1)->toString() == tri.rotation(origine,droit)->toString()) && (g2.get(2)->toString() == cer.rotation(origine,droit)->toString()) );

                     return true;
    });


    TESTCASE(translation,{
                 /*
        Groupe g2(*g.translation(vUn));
        assert(g2.get(0)->toString() == seg.translation(vUn)->toString());
        assert(g2.get(1)->toString() == tri.translation(vUn)->toString());
        assert(g2.get(2)->toString() == cer.translation(vUn)->toString());
*/
        return true;
    });

    TESTCASE(homothetie,{
                 /*
        Groupe g2(*g.homothetie(origine,1));
        assert( (g2.get(0)->toString() == g.get(0)->toString())  &&  (g2.get(1)->toString() == g.get(1)->toString() ) && (g2.get(2)->toString() == g.get(2)->toString()) );
        */
             return true;
     });



ENDTEST

#endif // TESTGROUPE_H
