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
#include "../../../Visual Studio 2013/Projects/projet_synthese_client/projet_synthese_client/erreur5.h"     // ma petite classe d'erreur personnelle
#pragma comment(lib, "ws2_32.lib") // sp�cifique � VISUAL C++
using namespace std;
#define L 20000 // longueur max d'une cha�ne de caract�res
int main()
{
	try
	{
		//-------------- initialisation ressources librairie winsock -------------------------------
		int r;
		WSADATA wsaData;        // structure contenant les donn�es de la librairie winsock � initialiser
		r = WSAStartup(MAKEWORD(2, 0), &wsaData);       // MAKEWORD(2,0) sert � indiquer la version de la librairie � utiliser : 1 pour winsock et 2 pour winsock2
		/* en cas de succ�s, wsaData a �t� initialis�e et l'appel a renvoy� la valeur 0 */
		//if (r) throw Erreur("L'initialisation a �chou�");
		cout << "client vers le serveur de majuscule" << endl;
		cout << "initialisation effectu�e" << endl;
		//---------------------- cr�ation socket -------------------------------------------------
		SOCKET sock;  // informations concernant le socket � cr�er : famille d'adresses accept�es, mode connect� ou non, protocole
		int familleAdresses = AF_INET;         // IPv4
		int typeSocket = SOCK_STREAM;           // mode connect� TCP
		int protocole = IPPROTO_TCP;            // protocole. On peut aussi mettre 0 et la fct choisit le protocole en fct des 2 1ers param�tres
		// pour les valeurs des param�tres : cf. fct socket dans la doc sur winsock
		sock = socket(familleAdresses, typeSocket, protocole);
		if (sock == INVALID_SOCKET)
		{
			ostringstream oss;
			oss << "la cr�ation du socket a �chou� : code d'erreur = " << WSAGetLastError() << endl;    // pour les valeurs renvoy�es par WSAGetLastError() : cf. doc r�f winsock
			//throw Erreur(oss.str().c_str());
		}
		cout << "socket cr��" << endl;
		//------------------------------ cr�ation du repr�sentant du serveur ----------------------------------------
		char adresseServeur[L];
		short portServeur;
		cout << "tapez l'adresse IP du serveur de majuscule : " << endl;
		cin >> adresseServeur;
		cout << "tapez le port du serveur du serveur de majuscule : " << endl;
		cin >> portServeur;
		SOCKADDR_IN sockaddr; // informations concernant le serveur avec lequel on va communiquer
		sockaddr.sin_family = AF_INET;
		sockaddr.sin_addr.s_addr = inet_addr(adresseServeur);   // inet_addr() convertit de l'ASCII en entier
		sockaddr.sin_port = htons(portServeur);                 //htons() assure que le port est bien inscrit dans le format du r�seau (little-endian ou big-endian)
		//-------------- connexion du client au serveur ---------------------------------------
		r = connect(sock, (SOCKADDR *)&sockaddr, sizeof(sockaddr));     // renvoie une valeur non nulle en cas d'�chec.
		// Le code d'erreur peut �tre obtenu par un appel � WSAGetLastError()
	//	if (r == SOCKET_ERROR)
			//throw Erreur("La connexion a �chou�");
		cout << "connexion au serveur de majuscule r�ussie" << endl;
		bool continuer;
		do
		{
			char requete[L];
			cout << "Tapez la cha�ne � mettre en majuscule ou tapez \"quitter\" : ";
			//cin >> requete;
			cin.getline(requete, L - 3, '\n');    // on utilise getline en entr�e, sinon avec cin l'espace est un s�parateur, ce qui engendra l'envoi de deux sockets
			// L-3 car => 1 pour '\n' , 2 pour "\r\n" 
			continuer = strcmp(requete, "quitter") != 0;
			if (continuer)
			{
				strcat(requete, "\r\n");     // pour que le serveur r�ceptionne bien le message
				int l = strlen(requete);
				r = send(sock, requete, l, 0);             //------------------ envoi de la requ�te au serveur -------------------------------
				// envoie au plus  l octets
			//	if (r == SOCKET_ERROR)
					//throw Erreur("�chec de l'envoi de la requ�te");
				char reponse[L];
				r = recv(sock, reponse, l, 0);             //----------- r�ception de la r�ponse du serveur -----------------------------
				// re�oit au plus l octets
				// en cas de succ�s, r contient le nombre d'octets re�us
				//if (r == SOCKET_ERROR)
					//throw Erreur("La r�ception de la r�ponse a �chou�");
				char * p = strchr(reponse, '\n');
				*p = '\0';

				cout << reponse << endl;
			}
		} while (continuer);
		r = shutdown(sock, SD_BOTH);                            // on coupe la connexion pour l'envoi et la r�ception
		// renvoie une valeur non nulle en cas d'�chec. Le code d'erreur peut �tre obtenu par un appel � WSAGetLastError()
	//	if (r == SOCKET_ERROR)
			//throw Erreur("la coupure de connexion a �chou�");
		r = closesocket(sock);                          // renvoie une valeur non nulle en cas d'�chec. Le code d'erreur peut �tre obtenu par un appel � WSAGetLastError()
		//if (r) throw Erreur("La fermeture du socket a �chou�");
		WSACleanup();
		cout << "arr�t normal du client" << endl;
	}
	catch (Erreur erreur)
	{
		cerr << erreur << endl;
	}
	return 0;
}
