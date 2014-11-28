#ifndef FORMECOMPOSEE_H
#define FORMECOMPOSEE_H
#include "formegeom.h"
#include <vector>


using std::vector;
template<class C,class T>
class FormeComposee : public FormeGeom {

protected:

    vector<C*> _composants;

public:

    vector<C*> getComposants()const{return _composants;}
    FormeComposee():FormeGeom(){}
    FormeComposee(const Couleurs::Couleur &couleur):FormeGeom(couleur){}
    FormeComposee(const Couleurs::Couleur &couleur, const vector<C*> &comp):
        FormeComposee(couleur)
    {
        for (C* p: comp){
            C* temp = new C(*p);
            _composants.push_back(temp);
        }
    }


    virtual FormeComposee<C,T>* rotation(const Point &p, const Angle &angle) const{
            //TODO: avec for_each
            T* ret = new T(*this);
            int i = 0;
            for(C* f: _composants){
                ret->_composants[i] = (f->rotation(p,angle));
                i++;
            }
            return ret;
    }


};
#endif // FORMECOMPOSEE_H
