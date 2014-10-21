#include "testcouleurs.h"
#include "../src/Couleur.h"

TestCouleurs::TestCouleurs(QObject *parent) :
    QObject(parent)
{
}


void TestCouleurs::CouleurToStringTestFalse(){
    QCOMPARE(Couleurs::isCouleur(string("rose")), false);
}
void TestCouleurs::CouleurToStringTestTrue(){
    QCOMPARE(Couleurs::isCouleur("black"), true);
}


//QTEST_MAIN(TestCouleurs)
//#include "testcouleurs.moc"
