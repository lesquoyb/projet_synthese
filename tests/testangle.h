#ifndef TESTANGLE_H
#define TESTANGLE_H
#include "cpptest.h"
#include "../src/angle.h"

CPPTEST(TestAngle)

    Angle droit(180);

    TESTCASE(getRadian,{
         equals(round(droit.getRadian()*100)/100, round(Angle::PI*100)/100);
     });

ENDTEST


#endif // TESTANGLE_H
