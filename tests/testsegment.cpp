#include "testsegment.h"


TestSegment::TestSegment(QObject *parent) :
    QObject(parent){}

void TestSegment::aire(){
    Segment s("red",Point("red",3.4,6.0),Point("black",5.0,9.0));
    QCOMPARE(s.aire(),0.0);
}

void TestSegment::rotationAngleNeg(){
    Segment depart("red",Point("red",9,1),Point("black",-3,6));
    Segment resultat("red",Point("red",-1,9),Point("black",6,3));
    depart.rotation(Point("red",0,0),Angle(-1.57)); // rotation de -90°
    cout << depart.getPoint1() <<endl<< depart.getPoint2()<<endl;
    QCOMPARE(depart.getPoint1(),resultat.getPoint1());
    QCOMPARE(depart.getPoint2(),resultat.getPoint2());

}

void TestSegment::rotation(){

}

void TestSegment::rotationAngleSup2Pi(){

}

void TestSegment::rotationZero(){

}

void TestSegment::translationTrue(){

}

void TestSegment::translationFalse(){

}

void TestSegment::translationByZero(){

}

void TestSegment::homothetieTrue(){

}

void TestSegment::homothetieFalse(){

}

void TestSegment::homothetieByZero(){

}

