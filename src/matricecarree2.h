#ifndef MATRICECARREE_H
#define MATRICECARREE_H
#include "vecteur.h"
#include "angle.h"
#include <math.h>

class MatriceCarree2{


private:

    Vecteur _l1;
    Vecteur _l2;


public:

    inline MatriceCarree2(const Vecteur &v1,const Vecteur &v2);
    inline MatriceCarree2(const double & x1, const double &y1, const double &x2, const double &y2);
    inline Vecteur getL1()const;
    inline Vecteur getL2()const;
    inline const Vecteur operator *(const Vecteur &v);
    static inline MatriceCarree2 getMatriceRotation(const Angle &a);
    static const MatriceCarree2 matriceIdentitee;

};


inline MatriceCarree2::MatriceCarree2(const double & x1, const double &y1, const double &x2, const double &y2): _l1(x1,y1),_l2(x2,y2){}
inline MatriceCarree2::MatriceCarree2(const Vecteur &v1,const Vecteur &v2):_l1(v1),_l2(v2){}
inline Vecteur MatriceCarree2::getL1()const{return _l1;}
inline Vecteur MatriceCarree2::getL2()const{return _l2;}

inline const Vecteur MatriceCarree2::operator *(const Vecteur &v){ return Vecteur( _l1 * v , _l2 * v ) ;}

inline MatriceCarree2 MatriceCarree2::getMatriceRotation(const Angle &a){
    double alpha = a.getRadian();
    Vecteur l1( cos(alpha) , -sin(alpha));
    Vecteur l2( sin(alpha) , cos(alpha) );
    return MatriceCarree2( l1 , l2);
}




#endif // MATRICECARREE_H
