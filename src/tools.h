#ifndef TOOLS_H
#define TOOLS_H
#include <string>
#include <sstream>
#include <vector>
#include <fstream>


using std::string;
using std::ostringstream;
using std::vector;
using std::ifstream;
using std::stringstream;

namespace tools {

vector<string> split(const string &s, char delim) ;

const string trim(const string &s);

const string lireFichier(ifstream &fichier);


}



#endif // TOOLS_H
