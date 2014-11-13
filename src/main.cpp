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

int main(){
    string entree;
    vector<FormeGeom*> liste;
    Segment s("red",Point(1,2),Point(50,50));
    Segment s2("red",Point(150,300),Point(50,50));
    Triangle t("red",Point(300,300),Point(50,50),Point(300,50));

    Cercle c(Point(80,90),90);
    Polygone p("yellow");
    p.ajouterPoint(Point(500,10));
    p.ajouterPoint(Point(400,100));
    p.ajouterPoint(Point(400,490));
    p.ajouterPoint(Point(500,490));
    p.ajouterPoint(Point(600,250));

    liste.push_back(&p);
    liste.push_back(&t);
    liste.push_back(&c);
    liste.push_back(&s);
    liste.push_back(&s2);
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

    */

/*
 *
    DessinManager* dessin = DessinManager::getDessinManager();
    s.dessin(*dessin);
    t.dessin(*dessin);
    c.dessin(*dessin);
    p.dessin(*dessin);

    cout << "continuer ?" <<endl;
    cin >> entree;
    if(entree == "o"){
        dessin->dessinerCercle(Cercle("red",Point(250,250),50));
    }

    */
    return 0;
}
