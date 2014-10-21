#include "tests/testcouleurs.h"
#include "tests/testgroupe.h"
#include "tests/testforme.h"
#include "tests/testsegment.h"


int main(int argc, char* argv[]){

    //tests unitaires
    TestCouleurs testCouleurs;
    QTest::qExec(&testCouleurs);

    TestGroupe testGroupe;
    QTest::qExec(&testGroupe);

    TestSegment testSeg;
    QTest::qExec(&testSeg);

    TestForme testF;
    QTest::qExec(&testF);

    // fin des tests unitaires


    return 0;
}
