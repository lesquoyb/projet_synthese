#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include "erreur.h"     // ma petite classe d'erreur personnelle
#include "dessinManager.h"

int main(){
    string entree;
	DessinManager* dessin = DessinManager::getDessinManager();
    Segment s("red",Point(1,2),Point(50,50));
    Segment s2("red",Point(300,300),Point(50,50));

    do{
        dessin->dessinerSegment(s);
        dessin->dessinerSegment(s2);
        dessin->deconnexion();
        cout << "continuer ?" <<endl;
        cin >> entree;
    }while(entree == "o");

    return 0;
}
