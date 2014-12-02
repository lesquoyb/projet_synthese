#ifndef TESTANGLE_H
#define TESTANGLE_H
#include "cpptest.h"
#include "../src/angle.h"


/**
  *@brief TestAngle
  * La classe de tests sur les angles.
  */
CPPTEST(TestAngle)

    Angle droit(180);

    TESTCASE(getRadian,{
         Equals(round(droit.getRadian()*100)/100, round(Angle::PI*100)/100);
     });

ENDTEST


#endif // TESTANGLE_H
