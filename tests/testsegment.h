#ifndef TESTSEGMENT_H
#define TESTSEGMENT_H
#include <QtTest>
#include "../src/segment.h"

class TestSegment : public QObject{

    Q_OBJECT
public:
    explicit TestSegment(QObject *parent = 0);

private slots:

    void aire();
    void rotationAngleNeg();
    void rotation();
    void rotationAngleSup2Pi();
    void rotationZero();
    void translationTrue();
    void translationFalse();
    void translationByZero();
    void homothetieTrue();
    void homothetieFalse();
    void homothetieByZero();
};

#endif // TESTSEGMENT_H
