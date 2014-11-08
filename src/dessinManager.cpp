#include "dessinManager.h"
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include "erreur.h"
#pragma comment(lib, "ws2_32.lib") // spécifique à VISUAL C++

#define L 20000 // longueur max d'une chaîne de caractères
using namespace std;

DessinManager* DessinManager::_me = NULL;



DessinManager::DessinManager(){

	//initialisation winsock
	WSADATA wsaData;								 
	int resultat = WSAStartup(MAKEWORD(2, 0), &wsaData);       //makeword(2,0) =  on utilise winsock2
	if (resultat){
		cout << "L'initialisation a échoué";
		//throw Erreur("L'initialisation a échoué");
	}
	cout << "winsock2 initialisé" << endl;

	//création du socket 
	int familleAdresses = AF_INET;          // IPv4
	int typeSocket = SOCK_STREAM;           // mode connecté TCP
	int protocole = IPPROTO_TCP;            // protocole. On peut aussi mettre 0 et la fct choisit le protocole en fct des 2 1ers paramètres
	_sock = socket(familleAdresses, typeSocket, protocole);
	if (_sock == INVALID_SOCKET){
		ostringstream oss;
		cout <<"la création du socket a échoué : code d'erreur = " << WSAGetLastError() << endl;
		
		//throw Erreur(oss.str().c_str());
	}
	cout << "socket créée" << endl;

	//boucle de connexion
	int connexion = SOCKET_ERROR;
	char adresseServeur[L];
	short portServeur;
	SOCKADDR_IN sockaddr; // informations concernant le serveur avec lequel on va communiquer
	sockaddr.sin_family = AF_INET;
	while (connexion == SOCKET_ERROR){

		//récupération des données sur le serveur
		cout << "tapez l'adresse IP du serveur de majuscule : " << endl;
		cin >> adresseServeur;
		cout << "tapez le port du serveur du serveur de majuscule : " << endl;
		cin >> portServeur;

		//initialisation de sockaddr
		sockaddr.sin_addr.s_addr = inet_addr(adresseServeur);   // inet_addr() convertit de l'ASCII en entier
		sockaddr.sin_port = htons(portServeur);                 //htons() assure que le port est bien inscrit dans le format du réseau (little-endian ou big-endian)
		
		// connexion du client au serveur
		if (connexion = connect(_sock, (SOCKADDR *) &sockaddr, sizeof(sockaddr)) == SOCKET_ERROR){
			cout << "la connexion a échouée, c'est peut être dû à une mauvaise adresse ip ou un mauvais port" << endl;
		}
	}
	cout << "connexion au serveur réussie" << endl;
}


void DessinManager::dessinerTriangle(const Triangle &t){
	

	//envoie au serveur
	char requete[L] = "triangle rectangle\r\n";
	int l = strlen(requete);
	if (send(_sock, requete, l, 0) == SOCKET_ERROR){
		cout << "échec de l'envoi de la requête";
		//throw Erreur("échec de l'envoi de la requête");
	}

    //réception de la réponse du serveur 
	char reponse[L];
	if (recv(_sock, reponse, l, 0) == SOCKET_ERROR){
		cout << "La réception de la réponse a échoué";
		//throw Erreur("La réception de la réponse a échoué");
	}

	cout << "le serveur a bien reçu le triangle" << endl;
}

DessinManager* DessinManager::getDessinManager(){
	if (_me == NULL){
		_me = new DessinManager();
	}
	return _me;
}

DessinManager::~DessinManager(){
	//TODO: certainement modifier, si déconnexion dans destructeur alors chaque instanciation = nouvelle connexion

	if (shutdown(_sock, SD_BOTH) == SOCKET_ERROR){
		ostringstream oss;
		cout << "la coupure de connexion a échoué" << WSAGetLastError() << endl;
		//throw Erreur(oss.str().c_str());
	}

	if (closesocket(_sock)){
		ostringstream oss;
		cout << "La fermeture du socket a échoué" << WSAGetLastError() << endl;
		//throw Erreur(oss.str().c_str());

	}
	WSACleanup();
	cout << "arrêt normal du client" << endl;
}
