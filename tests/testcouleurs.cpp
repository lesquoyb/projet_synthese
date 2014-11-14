#include "testcouleurs.h"
#include "../src/Couleur.h"



function<string()> TestCouleurs::CouleurToStringTestFalse = [] (){
    if(Couleurs::isCouleur(string("rose")) == false)
        return "";
    return "CouleurToStringTestFalse";
};
function<string()> TestCouleurs::CouleurToStringTestTrue = [] (){
    if(Couleurs::isCouleur("black") ==  true)
        return "";
    return "CouleurToStringTestTrue";
};

