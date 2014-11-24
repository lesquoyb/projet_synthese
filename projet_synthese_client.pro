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
    src/connexion.cpp \
    src/matricecarree2.cpp \
    src/chargementCOR/chargementgroupe.cpp \
    src/tools.cpp

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
    tests/testangle.h \
    src/matricecarree2.h \
    src/chargementCOR/expert.h \
    src/chargementCOR/chargementfacade.h \
    src/chargementCOR/expertcor.h \
    src/chargementCOR/expertchargement.h \
    src/chargementCOR/chargementsegment.h \
    exceptions/exceptiontraitementimpossible.h \
    src/chargementCOR/facade.h \
    src/chargementCOR/chargementtriangle.h \
    src/chargementCOR/chargementcercle.h \
    src/chargementCOR/chargementpolygone.h \
    src/chargementCOR/chargementgroupe.h \
    src/tools.h

FORMS    += src/mainwindow.ui

OTHER_FILES += \
    contraintes.ods \
    technos.txt \
    DiagrammeDeClasses.dia \
    DiagrammeDeClasses.png \
    rapport/contraintes.ods \
    rapport/DiagrammeDeClasses.dia \
    rapport/DiagrammeDeClassesTemporaire.dia \
    rapport/fonctionnement_chargement.dia \
    rapport/fonctionnement_client_serveur.dia \
    rapport/tests_unitaires.dia \
    rapport/DiagrammeDeClasses.png \
    rapport/rapport.tex \
    rapport/technos.txt
