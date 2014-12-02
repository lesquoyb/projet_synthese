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
/*

    MainWindow fenetre;
    fenetre.show();

    Segment s(Couleurs::red,Point(1,2),Point(50,50));
    Segment s2(Couleurs::red,Point(150,300),Point(50,50));
    Triangle t(Couleurs::red,Point(300,300),Point(50,50),Point(300,50));

    Cercle c(Point(0,0),90);
    Polygone p(Couleurs::Couleur::yellow, Point(500,10),Point(400,100),Point(400,490));
    p.ajouterPoint(Point(500,490));
    p.ajouterPoint(Point(600,250));

    Groupe g;

    g.ajouter(p);
    g.ajouter(s);
    g.ajouter(s2);
    g.ajouter(t);
    g.ajouter(c);
  //  g.ajouter(&g2);

   Connexion* connexion= new Connexion("127.0.0.1",9111);
   DessinManager dessin = DessinManager(connexion);
 //  Groupe g2(*g.translation(Vecteur(1,1)));

   g.dessin(DessinManager(connexion));
   /*
    Segment s1(Point(0,0),Point(-160,60));
    Cercle cercle(Point(-160,70),40);
    Segment d1(Point(-160,80),Point(-120,120));
    Segment d2(Point(-120,120),Point(-60,120));
    Segment* d3 = d1.translation(Vecteur(60,0));
    Groupe doigt1;
    doigt1.ajouter(&d1);
    doigt1.ajouter(&d2);
    doigt1.ajouter(d3);
    Vecteur interDoigt(60,0);
    FormeComposee<FormeGeom,Groupe>* fTemp = doigt1.translation(interDoigt);
    Groupe* doigt2 = new Groupe(*fTemp);
    delete fTemp;
    fTemp = doigt2->translation(interDoigt);
    Groupe* doigt3 = new Groupe(*fTemp);
    delete fTemp;
    fTemp = doigt3->translation(Vecteur(60,60));
    Groupe* temp = new Groupe(*fTemp);
    delete fTemp;
    doigt3 = temp;
    fTemp = doigt3->translation(Vecteur(30,0));
    temp = new Groupe(*fTemp);
    delete fTemp;
    fTemp = temp->homothetie(Point(0,0),0.75);
    delete temp;
    Groupe* temp2 = new Groupe(*fTemp);
    delete fTemp;
    doigt3->ajouter(temp2);
    //delete temp2;
    Segment* segTemp = new Segment(Point(-40,80),Point(20,140));
    doigt3->ajouter(segTemp);
    //delete segTemp;
    Segment* segTemp3 = new Segment(Point(20,80),Point(80,140));
    doigt3->ajouter(segTemp3);
    //delete segTemp;
    fTemp = doigt2->translation(interDoigt + interDoigt);
    temp2 = new Groupe(*fTemp);
    delete fTemp;
    Groupe* doigt4 = new Groupe(*temp2);
    fTemp = doigt4->translation(interDoigt+Vecteur(-40,-40));
    Groupe* doigt5 = new Groupe(*fTemp);
    delete fTemp;
   // doigt5.ajouter(cercle.translation(interDoigt+interDoigt+interDoigt+interDoigt+interDoigt+Vecteur(-interDoigt.getX()/2,10)));
    Groupe base;
    Segment* segTemp4 = new Segment(Point(40,-60),Point(100,40));
    base.ajouter(segTemp4);
 //   delete segTemp;
    Segment* segTemp2 = new Segment(Point(40,-60),Point(100,-80));
    base.ajouter(segTemp2);
   // delete segTemp;
    Groupe main;
    main.ajouter(&doigt1);
    main.ajouter(doigt2);
    main.ajouter(doigt3);
    main.ajouter(doigt4);
    main.ajouter(doigt5);
    main.ajouter(&base);
    main.dessin(dessin);
    delete doigt2;
    delete doigt3;
    delete doigt4;
    delete doigt5;
    delete segTemp;
    delete segTemp2;
    delete segTemp3;
    delete segTemp4;
    delete temp2;
/*
    s.sauvegarder("lolilol");
    t.sauvegarder("tritri");
    c.sauvegarder("cercle");
    p.sauvegarder("poly");
    g.sauvegarder("groupe");
    FormeGeom* forme = FormeGeom::chargement("lolilol");
    cout << endl << forme->toString() << endl;
     forme = FormeGeom::chargement("tritri");
    cout << endl << forme->toString() << endl;
    forme = FormeGeom::chargement("cercle");
    cout << endl << forme->toString() << endl;
    forme = FormeGeom::chargement("poly");
    cout << endl << forme->toString() << endl;
    forme = FormeGeom::chargement("groupe");
    cout << endl << forme->toString() << endl;

*/

/*
    string entree;
    while(1){
        DessinManager dessin(connexion);
        g.dessin(dessin);

        s.dessin(dessin);
        t.dessin(dessin);
        c.dessin(dessin);
        p.dessin(dessin);
        cin >> entree;
    }
*/



/*

    DessinManager dessin ;

    cout << "continuer ?" <<endl;
    cin >> entree;
    if(entree == "o"){
        dessin.dessinerCercle(Cercle("red",Point(250,250),50));
    }
	int lol;
	cin >> lol;
*/
  //  delete connexion;

    return a.exec();
    return 0;
}
