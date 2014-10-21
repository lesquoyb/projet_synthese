#include "testforme.h"
#include <QtTest>
#include "../src/formegeom.h"
#include "../src/point.h"

TestForme::TestForme(QObject *parent) :
    QObject(parent)
{}

void TestForme::Constructeur(){
    try{
        Point p("red",5.0,5.0);
        QCOMPARE(true,true);//pas d'erreur levé car la couleur existe
    }
    catch(exception e){
        QCOMPARE(true,false);
    }

}

void TestForme::ConstructeurAvecCouleurInexistante(){
    try{
        Point p("fausse couleur",5.0,5.0);
        QCOMPARE(true,false);//si on arrive jusque là il y a un problème
    }
    catch(exception e){
        QCOMPARE(true,true);//l'erreur doit être levé: bon comportement

    }
}

