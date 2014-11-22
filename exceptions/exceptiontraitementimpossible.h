#ifndef EXCEPTIONTRAITEMENTIMPOSSIBLE_H
#define EXCEPTIONTRAITEMENTIMPOSSIBLE_H
#include <exception>
#include <iostream>
#include <string.h>


class ExceptionTraitementImpossible : public std::exception{


   std::string _traitement;

public:
    ExceptionTraitementImpossible(const std::string traitement) throw(): _traitement(traitement){}

    virtual ~ExceptionTraitementImpossible()throw(){}

    virtual const char* what() const throw(){
        return strcat("impossible de traiter: " , _traitement.c_str());
    }
};

#endif // EXCEPTIONTRAITEMENTIMPOSSIBLE_H
