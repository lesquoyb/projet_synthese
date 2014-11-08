/*
* TestClientMajuscule.cpp
*
* Client vers le serveur de majuscule.
*
* T�che :
* 1) demande � l'utilisateur, l'adresse IP et le port du serveur de majuscule
* 2) se connecte au serveur
* 3) r�p�te perp�tuellement :
*      saisie d'une cha�ne de caract�res au clavier
*      envoi de la cha�ne au serveur
*      r�ception de la r�ponse du serveur (qui est la version majuscule de la cha�ne envoy�e)
* L'application s'arr�te si la cha�ne saisie est "quitter"
*
*/

#include <winsock2.h>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include "erreur.h"     // ma petite classe d'erreur personnelle
#include "dessinManager.h"

int main()
{
	DessinManager* dessin = DessinManager::getDessinManager();
	dessin->dessinerTriangle(Triangle("red",Point(1,2),Point(7,8),Point(50,50)));

	int i;
	cin >> i;
	return 0;
}
