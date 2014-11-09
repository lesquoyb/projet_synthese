#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include "erreur.h"     // ma petite classe d'erreur personnelle
#include "dessinManager.h"

int main(){

	DessinManager* dessin = DessinManager::getDessinManager();
    Triangle t("red",Point(1,2),Point(7,8),Point(50,50));
    dessin->dessinerTriangle(t);
    dessin->dessinerTriangle(t);
	dessin->deconnexion();

    return 0;
}
