/*
* TestClientMajuscule.cpp
*
* Client vers le serveur de majuscule.
*
* Tâche :
* 1) demande à l'utilisateur, l'adresse IP et le port du serveur de majuscule
* 2) se connecte au serveur
* 3) répète perpétuellement :
*      saisie d'une chaîne de caractères au clavier
*      envoi de la chaîne au serveur
*      réception de la réponse du serveur (qui est la version majuscule de la chaîne envoyée)
* L'application s'arrête si la chaîne saisie est "quitter"
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
