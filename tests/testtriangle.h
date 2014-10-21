#ifndef TESTTRIANGLE_H
#define TESTTRIANGLE_H
#include <QtTest>
#include <QObject>

class TestTriangle : public QObject
{
    Q_OBJECT
public:
    explicit TestTriangle(QObject *parent = 0);

signals:

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

#endif // TESTTRIANGLE_H
