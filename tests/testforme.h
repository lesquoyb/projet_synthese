#ifndef TESTFORME_H
#define TESTFORME_H
#include <QtTest/qtest.h>

class TestForme : public QObject{

    Q_OBJECT
public:

    explicit TestForme(QObject *parent = 0);


private slots:

    void Constructeur();
    void ConstructeurAvecCouleurInexistante();

};

#endif // TESTFORME_H
