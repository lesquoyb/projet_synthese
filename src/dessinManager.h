#include <winsock2.h>
#include "triangle.h"
#include "segment.h"
#include "polygone.h"

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
	~DessinManager();
	void test();
};