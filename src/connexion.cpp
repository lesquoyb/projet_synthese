#include "connexion.h"
#include "erreur.h"
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

bool Connexion::initialisee = false;



/**
* @brief Connexion::envoyer envoie le message au serveur
* @param message le message � envoyer
* Cette m�thode permet d'envoyer un message au serveur
* Il ne faut pas ajouter "\r\n" � la fin du message, la fonction s'en charge.
*/
void Connexion::envoyer(const char *message)const{
    char* envoie = strcat(strdup(message), "\r\n");
	int l = strlen(envoie);

	if (send(_sock, envoie, l, 0) == SOCKET_ERROR){
		throw Erreur("�chec de l'envoi de la requ�te" + WSAGetLastError());
	}
}


/**
* @brief DessinManager::recevoir
* @return la r�ponse du serveur, 0 (il y a eu une erreur) ou 1 (tout s'est bien pass�)
* Fonction � appeller apr�s chaque envoie de message, elle v�rifie que le message a bien �t� re�u par le serveur
*/
int Connexion::recevoir()const{
	char reponse[1];
	if (recv(_sock, reponse, 1, 0) == SOCKET_ERROR){
		throw Erreur("La r�ception de la r�ponse a �chou�");
	}
	cout << "reponse: " << reponse[0] << endl;
	return atoi(reponse);
}



Connexion::~Connexion(){

	if (shutdown(_sock, SD_BOTH) == SOCKET_ERROR){
		ostringstream oss;
		oss << "la coupure de connexion a �chou�" << WSAGetLastError() << endl;
		throw Erreur(oss.str().c_str());
	}

	if (closesocket(_sock)){
		ostringstream oss;
		oss << "La fermeture du socket a �chou�" << WSAGetLastError() << endl;
		throw Erreur(oss.str().c_str());

	}
	#ifdef WIN32
		WSACleanup();
	#endif
}


Connexion::Connexion(const string &ip, int host){

	#ifdef WIN32
		//initialisation winsock
		WSADATA wsaData;
		if (WSAStartup(MAKEWORD(2, 0), &wsaData)){
			throw Erreur("L'initialisation a �chou�");
		}
	#endif

	//cr�ation du socket 
	int familleAdresses = AF_INET;          // IPv4
	int typeSocket = SOCK_STREAM;           // mode connect� TCP
	int protocole = IPPROTO_TCP;            // protocole. On peut aussi mettre 0 et la fct choisit le protocole en fct des 2 1ers param�tres
	_sock = socket(familleAdresses, typeSocket, protocole);
	if (_sock == INVALID_SOCKET){
		ostringstream oss;
		oss << "la cr�ation du socket a �chou� : code d'erreur = " << WSAGetLastError() << endl;
		throw Erreur(oss.str().c_str());
	}

	SOCKADDR_IN sockaddr; // informations concernant le serveur avec lequel on va communiquer
    sockaddr.sin_family = AF_INET;

    //initialisation de sockaddr
    sockaddr.sin_addr.s_addr = inet_addr(ip.c_str());
    sockaddr.sin_port = htons(host);                 //htons() assure que le port est bien inscrit dans le format du r�seau (little-endian ou big-endian)

    // connexion du client au serveur
    if (connect(_sock, (SOCKADDR *)&sockaddr, sizeof(sockaddr)) == SOCKET_ERROR){
        ostringstream oss;
        oss << "la connexion a �chou�e, c'est peut �tre d� � une mauvaise adresse ip ou un mauvais port" << endl;
        cout << oss.str();
    }
}
