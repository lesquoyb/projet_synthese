#ifndef TESTGROUPE_H
#define TESTGROUPE_H
#include "cpptest.h"
#include "../src/groupe.h"
#include "../src/segment.h"
#include "../src/triangle.h"
#include "../src/cercle.h"
#include <assert.h>
#include <memory>


using std::unique_ptr;

/**
  *@brief TestGroupe
  * La classe de tests sur les groupes.
  */
CPPTEST(TestGroupe)

        Point origine(0,0);
        Segment seg(Point(1,2),Point(2,2));
        Triangle tri(Point(1,2),Point(2,2),origine);
        Cercle cer(origine,10);
        Angle droit(-90);
        Vecteur vUn(1,1);
        Cercle* c;
        Triangle* t;
        Segment* s;
        FormeGeom* f;
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
         s = seg.rotation(origine,droit);
         t = tri.rotation(origine,droit);
         c = cer.rotation(origine,droit);
         assert( (g2.get(0)->toString() == s->toString())  &&  (g2.get(1)->toString() == t->toString()) && (g2.get(2)->toString() == c->toString()) );
         delete s; delete t; delete c;
         return true;
    });


    TESTCASE(translation,{
        Groupe g2(*g.translation(vUn));
         s = seg.translation(vUn);
         t = tri.translation(vUn);
         c = cer.translation(vUn);
        assert(g2.get(0)->toString() == s->toString());
        assert(g2.get(1)->toString() == t->toString());
        assert(g2.get(2)->toString() == c->toString());
        delete s; delete t; delete c;
        return true;
    });

    TESTCASE(homothetie,{
                Groupe g2(*g.homothetie(origine,2));
                 f = g.get(0)->homothetie(origine,2);
                 assert( (g2.get(0)->toString() == f->toString()));
                 delete f;
                 f = g.get(1)->homothetie(origine,2);
                 assert(g2.get(1)->toString() == f->toString() ) ;
                 delete f;
                 f = g.get(2)->homothetie(origine,2);
                 assert(g2.get(2)->toString() == f->toString()) ;
                delete f;
                return true;
     });



ENDTEST

#endif // TESTGROUPE_H
