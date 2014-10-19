#ifndef TESTCOULEURS_H
#define TESTCOULEURS_H
#include <QtTest/qtest.h>
#include <QObject>

class TestCouleurs : public QObject{

    Q_OBJECT

public:

    explicit TestCouleurs(QObject *parent = 0);

signals:


private slots:

    void CouleurToStringTestFalse();
    void CouleurToStringTestTrue();
};

#endif // TESTCOULEURS_H
