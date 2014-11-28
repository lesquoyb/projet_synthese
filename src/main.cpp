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

#include "tests/testlauncher.h"


int main(){

    TestLauncher1 test;
    test.run();

    Segment s(Couleurs::red,Point(1,2),Point(50,50));
    Segment s2(Couleurs::Couleur::red,Point(150,300),Point(50,50));
    Triangle t(Couleurs::Couleur::red,Point(300,300),Point(50,50),Point(300,50));

    Cercle c(Point(0,0),90);
    Polygone p(Couleurs::Couleur::yellow, Point(500,10),Point(400,100),Point(400,490));
    p.ajouterPoint(Point(500,490));
    p.ajouterPoint(Point(600,250));

    Groupe g;

    g.ajouter(&p);
    g.ajouter(&s);
    g.ajouter(&s2);
    g.ajouter(&t);
    g.ajouter(&c);
  //  g.ajouter(&g2);

//   Connexion* connexion= new Connexion("127.0.0.1",9111);
   Groupe g2(*g.translation(Vecteur(1,1)));

 //  g.dessin(DessinManager(connexion));
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

    Point p1(2,1);
    cout << "point départ: " << p1 << endl;
    cout << "homothétie (-2,5) echelle 0.5" << endl;
    cout << "arrivée: " << *(p1.homothetie(Point(-2,5),0.5)) << endl;



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
    return 0;
}
