#include "Tools.h"
#include "formegeom.h"
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;



void sauvegarder(const vector<FormeGeom *> &v, const string&s){

    std::filebuf fb;
    fb.open (s,std::ios::out);
    std::ostream os(&fb);
    for(FormeGeom* f : v){
        os << f->toString() << endl;

    }
    fb.close();
}
