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
#include "Tools.h"

#include "tests/testlauncher.h"

int main(){

    TestLauncher1 test;
    test.run();

    Segment s(Couleurs::Couleur::red,Vecteur(1,2),Vecteur(50,50));
    Segment s2(Couleurs::Couleur::red,Vecteur(150,300),Vecteur(50,50));
    Triangle t(Couleurs::Couleur::red,Vecteur(300,300),Vecteur(50,50),Vecteur(300,50));

    Cercle c(Vecteur(0,0),90);
    Polygone p(Couleurs::Couleur::yellow,Vecteur(500,10),Vecteur(400,100),Vecteur(400,490));
    p.ajouterPoint(Vecteur(500,490));
    p.ajouterPoint(Vecteur(600,250));

    Groupe g;
    Groupe g2;
    g.ajouter(&p);
    g.ajouter(&s);
    g.ajouter(&s2);
    g2.ajouter(&t);
    g2.ajouter(&c);
    g.ajouter(&g2);
  //  Connexion* connexion= new Connexion("192.168.1.10",9111);
    s.sauvegarder("lolilol");
    ifstream stream;
    stream.open("lolilol",ios_base::in );
    FormeGeom* seg = FormeGeom::chargement("lolilol");
    cout << endl << seg->toString() << endl;

/*
    string entree;
    while(1){
        g.dessin(DessinManager(connexion));
        cin >> entree;
    }
*/

/*
    Point p1(2,1);
    cout << "point départ: " << p1 << endl;
    cout << "homothétie (-2,5) echelle 0.5" << endl;
    cout << "arrivée: " << *(p1.homothetie(Point(-2,5),0.5)) << endl;
*/
/*
    string fileAdd;
    cout << "dans quel fichier voulez vous sauver ?"<< endl;
    cin >> fileAdd;
    sauvegarder(liste, fileAdd);




    DessinManager dessin ;
    s.dessin(dessin);
    t.dessin(dessin);
    c.dessin(dessin);
    p.dessin(dessin);

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
