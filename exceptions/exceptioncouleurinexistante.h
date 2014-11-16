#ifndef EXCEPTIONCOULEURINEXISTANTE_H
#define EXCEPTIONCOULEURINEXISTANTE_H
#include <exception>
#include <iostream>

class ExceptionCouleurInexistante : public std::exception
{
    std::string couleur;

public:
    virtual ~ExceptionCouleurInexistante()throw(){}
    ExceptionCouleurInexistante(const std::string &s) throw() :
        couleur(s)
        {};

    virtual const char* what() const throw(){
        return couleur.c_str();
    }
};

#endif // EXCEPTIONCOULEURINEXISTANTE_H
