#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include "procedure.hpp"


class Function : public Procedure {
public:
    Function(std::string n, Type* t);
    Function(std::string n, ParameterList* p, Type* t);
    Type* getReturnType(){ return returnType; }
    int getReturnSize(){ return returnsize; }
private:
    Type* returnType;
    int returnsize;
};

#endif