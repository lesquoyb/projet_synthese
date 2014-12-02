#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include "erreur.h"
#include "cercle.h"
#include "triangle.h"
#include "segment.h"
#include "polygone.h"
#include "dessinManager.h"
#include "formegeom.h"
#include "groupe.h"

#include "tests/testlauncher.h"

#include <QApplication>
#include "mainwindow.h"


int main(int argc, char *argv[]){


    TestLauncher1 test;
    test.run();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
    return 0;
}
