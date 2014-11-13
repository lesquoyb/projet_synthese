#ifndef DESSINMANAGER_H
#define DESSINMANAGER_H

#include "dessinable.h"

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
//    #pragma comment(lib, "ws2_32.lib") // spécifique à VISUAL C++ peut être à retirer

#endif

/**
 * @brief The DessinManager class
 * Cette classe est chargé de dessiner les formes géometriques.
 * Le dessin est fait en envoyant les formes géometriques à un serveur distant afin que celui-ci dessine.
 * Cette classe est un singleton et on peut acceder à l'instance grace à la méthode getDessinManager().
 * De plus elle est compilable et fonctionnelle sous windows et unix (linux/mac compris) car la portabilité c'est la vie.
 */
class DessinManager : public Dessinable{


private:

	static DessinManager* _me;
	SOCKET _sock;

    DessinManager();
    void envoyer(const char *)const;
    int recevoir()const;

public:

	static DessinManager* getDessinManager();
    void dessinerCercle(const Cercle &c)const;
    void dessinerTriangle(const Triangle &t)const;
    void dessinerSegment(const Segment &s)const;
    void dessinerPolygone(const Polygone &p)const;
    ~DessinManager();

};

#endif
