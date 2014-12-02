#ifndef TESTLAUNCHER_H
#define TESTLAUNCHER_H
#include "cpptestfacade.h"
#include "testcouleurs.h"
#include "testpoint.h"
#include "testsegment.h"
#include "testtriangle.h"
#include "testcercle.h"
#include "testpolygone.h"
#include "testgroupe.h"
#include "testvecteur.h"
#include "testangle.h"
#include "testforme.h"

/**
  *@brief TestLauncher1
  * La façade lançant tous les tests unitaires du programme.
  */
TESTLAUNCHER(TestLauncher1)

    addTest(new TestCouleurs());
    addTest(new TestPoint());
    addTest(new TestSegment());
    addTest(new TestTriangle());
    addTest(new TestCercle());
    addTest(new TestPolygone());
    addTest(new TestGroupe());
    addTest(new TestVecteur());
    addTest(new TestAngle());
    addTest(new TestForme());

ENDLAUNCHER

#endif // TESTLAUNCHER_H
