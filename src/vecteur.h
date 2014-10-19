#ifndef VECTEUR_H
#define VECTEUR_H

class Vecteur{

private:
    Vecteur();
    double _deplacementX, _deplacementY;
public:

    Vecteur(double deplacementX, double deplacementY);

    double getDeplacementX()const;
    double getDeplacementY()const;

};

#endif // VECTEUR_H
