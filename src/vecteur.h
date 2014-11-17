#ifndef VECTEUR_H
#define VECTEUR_H



class Point;

class Vecteur{

private:

    double _deplacementX, _deplacementY;
public:

    Vecteur(double deplacementX, double deplacementY);

    double getDeplacementX()const;
    double getDeplacementY()const;
    friend Vecteur operator* (const Vecteur &v, double c);
    friend Vecteur operator* (double c, const Vecteur &v);
    Vecteur operator* (const Vecteur& v);
    double norme()const;
};

#endif // VECTEUR_H
