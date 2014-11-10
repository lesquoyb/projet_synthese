#include "dessinManager.h"
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include "erreur.h"

#define L 20000 // longueur max d'une cha�ne de caract�res
using namespace std;

DessinManager* DessinManager::_me = NULL;


DessinManager::DessinManager(){

		//initialisation winsock
     #ifdef WIN32
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

		//boucle de connexion
        int connexion = SOCKET_ERROR;
        string adresseServeur;
        int portServeur;
		SOCKADDR_IN sockaddr; // informations concernant le serveur avec lequel on va communiquer
        sockaddr.sin_family = AF_INET;
        while (connexion == SOCKET_ERROR){
            //r�cup�ration des donn�es sur le serveur
            cout << "tapez l'adresse IP du serveur: " << endl;
            cin.clear();
            cin >> adresseServeur;
            cout << "tapez le port du serveur du serveur: " << endl;
            cin >> portServeur;

            //initialisation de sockaddr
            sockaddr.sin_addr.s_addr = inet_addr(adresseServeur.c_str());
            sockaddr.sin_port = htons(portServeur);                 //htons() assure que le port est bien inscrit dans le format du r�seau (little-endian ou big-endian)

            // connexion du client au serveur
            if ( ( connexion = connect(_sock, (SOCKADDR *) &sockaddr, sizeof(sockaddr)) ) == SOCKET_ERROR){
                ostringstream oss;
                oss << "la connexion a �chou�e, c'est peut �tre d� � une mauvaise adresse ip ou un mauvais port" << endl;
                cout << oss.str();
            }

        }
}

/**
 * @brief DessinManager::envoyer envoie le message au serveur
 * @param message le message � envoyer
 * Cette m�thode permet d'envoyer un message au serveur, les messages sont les objets g�om�triques avec un certain formats.
 * Il ne faut pas ajouter "\r\n" � la fin du message, la fonction s'en charge.
 */
void DessinManager::envoyer(char *message){
    char* envoie = strcat(message, "\r\n");
    int l = strlen(envoie);
    if (send(_sock, envoie, l, 0) == SOCKET_ERROR){
        throw Erreur("�chec de l'envoi de la requ�te" + WSAGetLastError());
    }
}

/**
 * @brief DessinManager::recevoir
 * @return la r�ponse du serveur, 0 (il y a eu une erreur) ou 1 (tout c'est bien pass�)
 * Fonction � appeller apr�s chaque envoie de message, elle v�rifie que le message a bien �t� re�u par le serveur
 */
int DessinManager::recevoir(){
    char reponse[1];
    if (recv(_sock, reponse, 1, 0) == SOCKET_ERROR){
        throw Erreur("La r�ception de la r�ponse a �chou�");
    }
    return atoi(reponse);
}

void DessinManager::dessinerTriangle(const Triangle &t){
	
    //envoyer("triangle rectangle\r\n");

    //r�ception de la r�ponse du serveur 
    if(recevoir() != 0 ){
        cout << "le serveur a bien re�u le triangle" << endl;
    }
    else{
        cout << "il y a eu une erreur lors de l'envoie"<< endl;
    }

}

void DessinManager::dessinerSegment(const Segment &s){
    ostringstream message ;
    message << "segment: #FFEEFF," << s.getPoint1().getX() << "," << s.getPoint1().getY() << "," << s.getPoint2().getX() << "," << s.getPoint2().getY();
    //TODO conversion de la couleur en hexa
    envoyer(const_cast<char*>(message.str().c_str()));
    if(recevoir() != 0 ){
        cout << "le serveur a bien re�u le triangle" << endl;
    }
    else{
        cout << "il y a eu une erreur lors de l'envoie"<< endl;
    }
}

DessinManager* DessinManager::getDessinManager(){
	if (_me == NULL){
		_me = new DessinManager();
	}
	return _me;
}

void DessinManager::deconnexion(){

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


