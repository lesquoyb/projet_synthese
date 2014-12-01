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

    vector<FormeGeom*> formes;
    QListWidget* listeFormes;

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_ajout_cercle_clicked();

    void on_ajout_segment_clicked();

    void on_ajout_triangle_clicked();

private:

    void rafraichirListe();

    Ui::MainWindow *ui;



};

#endif // MAINWINDOW_H
