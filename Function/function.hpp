#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include "procedure.hpp"


class Function : public Procedure {
public:
    Type* getReturnType(){ return returnType; }
    int getReturnSize(){ return returnsize; }
private:
    Type* returnType;
    int returnsize;
};

#endif