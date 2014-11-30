#ifndef TESTFORME_H
#define TESTFORME_H
#include "cpptest.h"
#include "../src/groupe.h"
#include "../src/polygone.h"
#include <memory>

CPPTEST(TestForme)

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
Polygone p(origine,Point(1,1),Point(2,2));


TESTCASE(testSauvCharSegment,{
            seg.sauvegarder("testSegment.test");
            std::unique_ptr<FormeGeom> s (FormeGeom::chargement("testSegment.test"));
            equals(s->toString(),seg.toString());
         });


TESTCASE(testSauvCharTriangle,{
             tri.sauvegarder("testTriangle.test");
             std::unique_ptr<FormeGeom> s (FormeGeom::chargement("testTriangle.test"));
             equals(s->toString(),tri.toString());
         });

TESTCASE(testSauvCharCercle,{
             cer.sauvegarder("testCercle.test");
             std::unique_ptr<FormeGeom> s (FormeGeom::chargement("testCercle.test"));
             equals(s->toString(),cer.toString());
         });

TESTCASE(testSauvCharPolygone,{
             p.sauvegarder("testPoly.test");
             std::unique_ptr<FormeGeom> s (FormeGeom::chargement("testPoly.test"));
             cout << "p: " << p.toString();
             cout << endl << "charg: " << s->toString();
             equals(s->toString(),p.toString());
         });

TESTCASE(testSauvCharGroupe,{
             g.sauvegarder("testGroupe.test");
             std::unique_ptr<FormeGeom> s (FormeGeom::chargement("testGroupe.test"));
             equals(s->toString(),g.toString());
         });

ENDTEST

#endif // TESTFORME_H
