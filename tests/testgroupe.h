#ifndef TESTGROUPE_H
#define TESTGROUPE_H
#include <QtTest/qtest.h>

class TestGroupe :public QObject{

    Q_OBJECT
public:

    explicit TestGroupe(QObject *parent = 0);


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
    void Destructeur();
};

#endif // TESTGROUPE_H
