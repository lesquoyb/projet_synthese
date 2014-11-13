#ifndef TOOLS_H
#define TOOLS_H

#include <vector>
#include <fstream>


namespace tools {
static const double PI= 3.14159265359;
}

class FormeGeom;
void sauvegarder(const std::vector<FormeGeom*> &v, const std::string &s);

#endif // TOOLS_H
