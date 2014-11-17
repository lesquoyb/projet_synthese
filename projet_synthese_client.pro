#-------------------------------------------------
#
# Project created by QtCreator 2014-10-18T19:09:45
#
#-------------------------------------------------

QT       += core gui\
            testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = projet_synthese_client
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

SOURCES += src/formegeom.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/point.cpp \
    src/vecteur.cpp \
    src/Couleur.cpp \
    src/groupe.cpp \
    src/segment.cpp \
    src/cercle.cpp \
    src/triangle.cpp \
    src/polygone.cpp \
    src/dessinManager.cpp \
    src/erreur.cpp \
    src/tools.cpp \
    src/connexion.cpp

HEADERS  += src/Couleur.h \
    src/formegeom.h \
    src/mainwindow.h \
    tests/testcouleurs.h \
    src/angle.h \
    src/point.h \
    src/vecteur.h \
    exceptions/exceptioncouleurinexistante.h \
    src/groupe.h \
    tests/testgroupe.h \
    src/segment.h \
    tests/testsegment.h \
    src/cercle.h \
    src/Tools.h \
    src/triangle.h \
    tests/testtriangle.h \
    src/polygone.h \
    src/dessinManager.h \
    src/erreur.h \
    src/dessinable.h \
    src/connexion.h \
    tests/ testpoint.h \
    tests/testpoint.h \
    tests/cunittools.h \
    tests/testlauncher.h \
    tests/cunit.h \
    tests/cunitfacade.h \
    tests/cpptest.h \
    tests/cpptestfacade.h \
    tests/cpptesttools.h \
    tests/testvecteur.h \
    tests/testcercle.h \
    tests/testpolygone.h \
    tests/testangle.h

FORMS    += src/mainwindow.ui

OTHER_FILES += \
    contraintes.ods \
    technos.txt \
    DiagrammeDeClasses.dia \
    DiagrammeDeClasses.png
