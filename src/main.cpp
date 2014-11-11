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


int main(){
    string entree;
	DessinManager* dessin = DessinManager::getDessinManager();
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


    s.dessin(*dessin);
    t.dessin(*dessin);
    c.dessin(*dessin);
    p.dessin(*dessin);

    cout << "continuer ?" <<endl;
    cin >> entree;
    if(entree == "o"){
        dessin->dessinerCercle(Cercle("red",Point(250,250),50));
    }

    return 0;
}
