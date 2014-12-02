#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "erreur.h"

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
    for(FormeGeom* f : _formes){
        delete f;
    }

    /* // pas besoin car valeurs partagées entre les vector
    for(Polygone* p : _polygones){
        delete p;
    }
    for(Groupe* g : _groupes){
        delete g;
    }
    */
}

/**
 * @brief MainWindow::rafraichirListe
 * Rafraîchit l'affichage de la liste.
 */
void MainWindow::rafraichirListe(){
    listeFormes->clear();
    ui->listeGroupe->clear();
    for(FormeGeom* f : _formes){
        listeFormes->addItem(QString(f->toString().c_str()));
    }
    for(Groupe* g: _groupes){
        if ( g != NULL ){
            ui->listeGroupe->addItem(QString(g->toString().c_str()));
        }
    }
}

/**
 * @brief MainWindow::on_ajout_cercle_clicked
 * Ajoute un cercle à la liste.
 */
void MainWindow::on_ajout_cercle_clicked(){
    Point centre(ui->centreX->value(),ui->centreY->value());
    Couleurs::Couleur couleur = Couleurs::intToCouleur(ui->couleurCercle->currentIndex());
    Cercle c(couleur,centre,ui->rayon->value());
    _formes.push_back(c.clone());
    rafraichirListe();
}


/**
 * @brief MainWindow::on_ajout_segment_clicked
 * Ajoute un segment à la liste
 */
void MainWindow::on_ajout_segment_clicked(){
    Point p1(ui->sP1X->value(),ui->sP1Y->value());
    Point p2(ui->sP2X->value(),ui->sP2Y->value());
    Couleurs::Couleur couleur = Couleurs::intToCouleur(ui->couleurSegment->currentIndex());
    Segment s(couleur,p1,p2);
    _formes.push_back(s.clone());
    rafraichirListe();
}

/**
 * @brief MainWindow::on_ajout_triangle_clicked
 * Ajoute un triangle à la liste
 */
void MainWindow::on_ajout_triangle_clicked(){
    Point p1(ui->tP1X->value(),ui->tP1Y->value());
    Point p2(ui->tP2X->value(),ui->tP2Y->value());
    Point p3(ui->tP3X->value(),ui->tP3Y->value());
    Couleurs::Couleur couleur = Couleurs::intToCouleur(ui->couleurTriangle->currentIndex());
    Triangle t(couleur,p1,p2,p3);
    _formes.push_back(t.clone());
    rafraichirListe();
}





/**
 * @brief MainWindow::on_ajouterPoint_clicked
 * ajoute un point au polygone selectionné
 */
void MainWindow::on_ajouterPoint_clicked(){
    int index = ui->listeFormes->currentRow();
    if(  (index != -1) and  (_polygones[index] != NULL) ){//On vérifie qu'on a bien selectionné un polygone
        Point p (ui->ajoutPX->value(),ui->ajoutPY->value());
        _polygones[index]->ajouterPoint(p);
    }
    rafraichirListe();
}


void MainWindow::on_ajout_polygone_clicked(){
    Point p1(ui->pP1X->value(),ui->pP1Y->value());
    Point p2(ui->pP2X->value(),ui->pP2Y->value());
    Point p3(ui->pP3X->value(),ui->pP3Y->value());
    Couleurs::Couleur couleur = Couleurs::intToCouleur(ui->couleurPolygone->currentIndex());
    Polygone p(couleur,p1,p2,p3);
    Polygone* poly = p.clone();
    _formes.push_back(poly);
    _polygones.push_back(poly);
    rafraichirListe();
}

void MainWindow::on_creer_groupe_clicked(){
    Couleurs::Couleur couleur = Couleurs::intToCouleur(ui->couleurGroupe->currentIndex());
    Groupe p(couleur);
    Groupe* groupe = p.clone();
    _formes.push_back(groupe);
    _groupes.push_back(groupe);
    rafraichirListe();
}

void MainWindow::on_ajout_groupe_clicked(){
    int indexForme =  ui->listeFormes->currentRow();
    int indexGroupe = ui->listeGroupe->currentRow();
    if ( (indexForme != -1) and (indexGroupe != -1) and (_groupes[indexGroupe] != _formes[indexForme]) ){
        FormeGeom* f = _formes[indexForme];
        _groupes[indexGroupe]->ajouter(*f);

        // On supprime la forme des listes.
        int i = 0;
        for(Groupe* g: _groupes){
            if(g == f){
                _groupes.erase(_groupes.begin()+i);
                break;
            }
            i++;
        }

        i = 0;
        for(Polygone* p : _polygones){
            if (p == NULL){
                _polygones.erase(_polygones.begin()+i);
                break;
            }
            i++;
        }
        delete f;
        _formes.erase( _formes.begin()+indexForme);

    }
    rafraichirListe();
}

void MainWindow::on_dessiner_tout_clicked(){
    if(_dessinManager != NULL){
        for(FormeGeom* f : _formes){
            f->dessin(*_dessinManager);
        }
    }
}

void MainWindow::on_dessiner_forme_clicked(){
    if(_dessinManager != NULL){
        int index =  ui->listeFormes->currentRow();
        if( index != -1 ){
            _formes[index]->dessin(*_dessinManager);
        }
    }
}

void MainWindow::on_connexion_clicked(){

    try{
        if(_connexion != NULL){
            delete _connexion;
            _connexion = NULL;
        }
        _connexion = new Connexion(ui->ip->text().toStdString(),ui->port->text().toInt());
    }
    catch(Erreur e){
        _connexion = NULL;
    }

    if(_connexion != NULL){
        _dessinManager = new DessinManager(_connexion);
        ui->status_reseau->setPixmap(QPixmap(":images/ressources/images/Green_check.png"));
    }
    else{
        ui->status_reseau->setPixmap(QPixmap(":images/ressources/images/echec.png"));

    }
}
