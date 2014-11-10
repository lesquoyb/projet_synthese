#include "triangle.h"
#include "segment.h"
#include "polygone.h"

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
class DessinManager{


private:

	static DessinManager* _me;
	SOCKET _sock;

	DessinManager();
    void envoyer(char *);
    int recevoir();

public:

	static DessinManager* getDessinManager();
	void dessinerTriangle(const Triangle &t);
	void dessinerSegment(const Segment &s);
	void dessinerPolygone(const Polygone &p);
    ~DessinManager(){/*TODO*/};
	void deconnexion();

};
