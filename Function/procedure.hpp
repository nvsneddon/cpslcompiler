#ifndef PROCEDURE_HPP
#define PROCEDURE_HPP

#include <map>
#include <iostream>

#include "../Types/type.hpp"
#include "parameterlist.hpp"


class Procedure {

public:
    Procedure(std::string);
    void declare();
    void call();
    std::map<std::string, Type*> params;
    int getStackSize() { return stacksize; }
    void declareParameters();
protected:
    std::string name;
    ParameterList plist;
    int stacksize;
};

#endif