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


SOURCES += src/formegeom.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    tests/testcouleurs.cpp \
    src/angle.cpp \
    src/point.cpp \
    src/vecteur.cpp \
    src/Couleur.cpp \
    src/groupe.cpp

HEADERS  += src/Couleur.h \
    src/formegeom.h \
    src/mainwindow.h \
    tests/testcouleurs.h \
    src/angle.h \
    src/point.h \
    src/vecteur.h \
    exceptions/exceptioncouleurinexistante.h \
    src/groupe.h

FORMS    += src/mainwindow.ui
