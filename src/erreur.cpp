#include "erreur.h"
ostream & operator << (ostream & os, const Erreur & erreur){
	os << erreur.message << endl;
	return os;
}