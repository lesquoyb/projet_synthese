#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
    {
        ui->setupUi(this);
        QStringList model;
        listeFormes = ui->listeFormes;
    }

MainWindow::~MainWindow(){
    delete ui;
    for(FormeGeom* f : formes){
        delete f;
    }
}

void MainWindow::on_ajout_cercle_clicked(){
    Point centre(ui->centreX->value(),ui->centreY->value());
    Couleurs::Couleur couleur = Couleurs::intToCouleur(ui->couleurCercle->currentIndex());
    Cercle c(couleur,centre,ui->rayon->value());
    formes.push_back(c.clone());
    rafraichirListe();
}

void MainWindow::rafraichirListe(){
    listeFormes->clear();
    for(FormeGeom* f : formes){
        listeFormes->addItem(QString(f->toString().c_str()));
    }
}

void MainWindow::on_ajout_segment_clicked(){
    Point p1(ui->sP1X->value(),ui->sP1Y->value());
    Point p2(ui->sP2X->value(),ui->sP2Y->value());
    Couleurs::Couleur couleur = Couleurs::intToCouleur(ui->couleurSegment->currentIndex());
    Segment s(couleur,p1,p2);
    formes.push_back(s.clone());
    rafraichirListe();
}

void MainWindow::on_ajout_triangle_clicked(){
    Point p1(ui->tP1X->value(),ui->tP1Y->value());
    Point p2(ui->tP2X->value(),ui->tP2Y->value());
    Point p3(ui->tP3X->value(),ui->tP3Y->value());
    Couleurs::Couleur couleur = Couleurs::intToCouleur(ui->couleurTriangle->currentIndex());
    Triangle t(couleur,p1,p2,p3);
    formes.push_back(t.clone());
    rafraichirListe();
}





