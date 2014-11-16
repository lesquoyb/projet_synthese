#ifndef TESTGROUPE_H
#define TESTGROUPE_H
#include "test.h"
#include "../src/groupe.h"
#include "../src/segment.h"
#include "../src/triangle.h"
#include "../src/cercle.h"


class TestGroupe : public CUNIT{

    Groupe _dataTest;
    int _dataSize;

    Point dtPoint;
    Segment dtSeg;
    Triangle dtTriangle;
    Cercle dtCercle;

public:

    TestGroupe():
        _dataTest("black"),
        dtPoint(0,0),
        dtSeg("red",Point(1,2),Point(2,2)),
        dtTriangle("red",Point(1,2),Point(2,2),dtPoint),
        dtCercle("red",dtPoint,10)  {
        CUNIT::_name = "TestGroupe";
        /*
        _functions.push_back(aire);
        _functions.push_back(rotationAngleNeg);
        _functions.push_back(rotation);
        _functions.push_back(rotationAngleSup2Pi);
        _functions.push_back(rotationZero);
        _functions.push_back(translationTrue);
        _functions.push_back(translationFalse);
        _functions.push_back(translationByZero);
        _functions.push_back(homothetieByZero);
        _functions.push_back(homothetieNegatif);
        _functions.push_back(homothetieByOne);
        _functions.push_back(homothetieScaleSup1);
        _functions.push_back(homothetieScaleInf1);


    */
        //_dataTest.ajouter(dtPoint);
        _dataTest.ajouter(&dtSeg);
        _dataTest.ajouter(&dtTriangle);
        _dataTest.ajouter(&dtCercle);
        // TODO: ajouter polygone
        _dataSize = _dataTest.getNbElem();

    }



    function<string()> aire = [&](){
        if( _dataTest.aire() == (dtCercle.aire() + (dtTriangle.aire()) ) )
            return "";
        return "aire";
    };

    function<string()> rotationAngleNeg = [&](){
        Angle a(-90);
        Point p(dtPoint);
      //  Groupe g = _dataTest.rotation(p,a);
      //  if(g.get(0) == dtSeg.rotation(p,a)) and (g.get(1) == dtTriangle.rotation(p,a)) and (g.get(2) == dtCercle.rotation(p,a)) and (g.get(3) == )
        return "";
    };
    function<string()> rotation = [](){
        //TODO
        return "aire";
    };
    function<string()> rotationAngleSup2Pi = [](){
        //TODO
        return "aire";
    };
    function<string()> rotationZero;
    function<string()> translationTrue;
    function<string()> translationFalse;
    function<string()> translationByZero;
    function<string()> homothetieTrue;
    function<string()> homothetieByZero;
    function<string()> homothetieNegatif;
    function<string()> homothetieByOne;
    function<string()> homothetieScaleSup1;
    function<string()> homothetieScaleInf1;
};


#endif // TESTGROUPE_H
