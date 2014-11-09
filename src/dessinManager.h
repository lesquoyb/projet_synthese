#include "triangle.h"
#include "segment.h"
#include "polygone.h"

#ifdef __linux
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

class DessinManager{


private:
	static DessinManager* _me;
	SOCKET _sock;

	DessinManager();
	void envoyer();
	void recevoir();

public:

	static DessinManager* getDessinManager();
	void dessinerTriangle(const Triangle &t);
	void dessinerSegment(const Segment &s);
	void dessinerPolygone(const Polygone &p);
	~DessinManager(){};
	void deconnexion();

};
