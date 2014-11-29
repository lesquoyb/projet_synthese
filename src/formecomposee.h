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


    vector<C*> getComposants()const{return _composants;}


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

    virtual FormeComposee<C,T>* homothetie(const Point &p, const double &d) const{
        T* g2 = new T(*this);
        int i = 0;
        for_each(_composants.begin(),_composants.end(),[&,p,&g2,d,&i](C* f) { g2->_composants[i] = f->homothetie(p,d); i++; });
        return g2;
    }


    virtual FormeComposee<C,T>* translation(const Vecteur &v) const{
        T* g2 = new T(*this);
        int i = 0;
        for_each(_composants.begin(),_composants.end(),[&,v,&g2,&i](C* f) { g2->_composants[i] = f->translation(v);  i++;});
        return g2;
    }



};
#endif // FORMECOMPOSEE_H
