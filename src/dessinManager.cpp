#include "dessinManager.h"
#include "triangle.h"
#include "cercle.h"
#include "segment.h"
#include "polygone.h"
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include "erreur.h"

using namespace std;




DessinManager::DessinManager(Connexion *c):
_connexion(c){}



void DessinManager::dessinerTriangle(const Triangle &t) const{

    string message = t.toString();
    cout << message;
    _connexion->envoyer(message.c_str());

	if (_connexion->recevoir() != 0){
		cout << "le serveur a bien re�u le triangle" << endl;
	}
	else{
		cout << "il y a eu une erreur lors de l'envoie" << endl;
	}

}


void DessinManager::dessinerSegment(const Segment &s) const{
    string message = s.toString();
    cout << message;
    _connexion->envoyer(message.c_str());

	if (_connexion->recevoir() != 0){
		cout << "le serveur a bien re�u le segment" << endl;
	}
	else{
		cout << "il y a eu une erreur lors de l'envoie" << endl;
	}

}



void DessinManager::dessinerCercle(const Cercle &c) const{
    string message = c.toString();
    cout << message;
    _connexion->envoyer(message.c_str());

	if (_connexion->recevoir() != 0){
		cout << "le serveur a bien re�u le cercle" << endl;
	}
	else{
		cout << "il y a eu une erreur lors de l'envoie" << endl;
	}
}


void DessinManager::dessinerPolygone(const Polygone &p) const{
    string message = p.toString();
    cout << message;
    _connexion->envoyer(message.c_str());

	if (_connexion->recevoir() != 0){
		cout << "le serveur a bien re�u le polygone" << endl;
	}
	else{
		cout << "il y a eu une erreur lors de l'envoie" << endl;
	}
}






