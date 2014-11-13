#ifndef CONNEXION_H
#define CONNEXION_H

#define _CRT_SECURE_NO_WARNINGS

#ifdef  __unix__

    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    #include <errno.h>


    #define INVALID_SOCKET -1
    #define SOCKET_ERROR -1
    #define WSAGetLastError() errno
    #define SD_BOTH 2
    #define closesocket(s) close(s)
    typedef int SOCKET;
    typedef struct sockaddr_in SOCKADDR_IN;
    typedef struct sockaddr SOCKADDR;

#else

    #include <winsock2.h>
    #pragma comment(lib, "ws2_32.lib") // sp�cifique � VISUAL C++ peut �tre � retirer

#endif



/**
* @brief The Connexion class
* Cette classe est charg�e d'�tablire une connexion avec un serveur distant
* Cette classe est un singleton et on peut acceder � l'instance grace � la m�thode getDessinManager().
* De plus elle est compilable et fonctionnelle sous windows et unix(linux / mac compris) car la portabilit� c'est la vie.
*/
class Connexion{
	
private:

	static Connexion* _me;
	SOCKET _sock;
	Connexion();
	
public:
	
	static Connexion* getConnexion();
	void envoyer(const char *)const;
    int recevoir()const;
	~Connexion();

};

#endif