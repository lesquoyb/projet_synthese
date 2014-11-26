#include "tools.h"



vector<string> tools::split(const string &s, char delim) {
    vector<string> elems;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

const string tools::trim(const string &s){
    string copy(s);
    int i;
    for(i = 0 ; i < s.size() and (s[i] == ' ' or s[i] == '\n' or s[i] == '\r' ); i++){}
    copy.erase(copy.find_last_not_of(" \n\r\t")+1);
    return copy.substr(i);
}



const string tools::lireFichier(ifstream &fichier){
    string str;
    ostringstream oss;
    while( getline( fichier, str ) ){
        oss << str;
    }
    return trim(oss.str());
}



