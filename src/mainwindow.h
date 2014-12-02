#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "groupe.h"
#include "cercle.h"
#include "segment.h"
#include "triangle.h"
#include "polygone.h"
#include <QApplication>
#include <QMainWindow>
#include <qlistwidget.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{

    Q_OBJECT

    vector<FormeGeom*> _formes;
    vector<Polygone*> _polygones;
    vector<Groupe*> _groupes;
    QListWidget* listeFormes;
    Connexion* _connexion;
    DessinManager* _dessinManager;

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_ajout_cercle_clicked();

    void on_ajout_segment_clicked();

    void on_ajout_triangle_clicked();

    void on_ajouterPoint_clicked();

    void on_ajout_polygone_clicked();

    void on_creer_groupe_clicked();

    void on_ajout_groupe_clicked();

    void on_dessiner_tout_clicked();

    void on_dessiner_forme_clicked();

    void on_connexion_clicked();

private:

    void rafraichirListe();

    Ui::MainWindow *ui;



};

#endif // MAINWINDOW_H
