#include <winsock2.h>
#include "triangle.h"
#include "segment.h"
#include "polygone.h"

class DessinManager{


private:
	static DessinManager* _me;
	DessinManager();
	static void envoyer();
	static void recevoir();

public:

	static DessinManager* getDessinManager();
	static void dessinerTriangle(const Triangle &t);
	static void dessinerSegment(const Segment &s);
	static void dessinerPolygone(const Polygone &p);
	static void test();
};