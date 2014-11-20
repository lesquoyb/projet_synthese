#include <iostream>
#include "vecteur.h"

using namespace std;

int main()
{
    Vecteur v1(2,3), v2(5,7),v3;
    //v3 = 5 ; refusé
    v3 = v1+v2;
    cout << "v1= " << v1 << endl;
    cout << "v2= " << v2 << endl;
    cout << "v1 + v2= " << v3 << endl;
    v3 = v1 * 5;
    cout << "v1= " << v1 << endl;
    cout << "v1 *5= " << v3 << endl;
    v3 =  5 * v1;
    cout << "v1= " << v1 << endl;
    cout << "5 * v1= " << v3 << endl;
    v3 =  -v1;
    cout << "v1= " << v1 << endl;
    cout << "-v1= " << v3 << endl;
    v3 =  v2-v1;
    cout << "v1= " << v1 << endl;
    cout << "v2= " << v2 << endl;
    cout << "v2 -v1= " << v3 << endl;
    return 0;
}

