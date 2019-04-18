#ifndef PROCEDURE_HPP
#define PROCEDURE_HPP

#include <map>
#include <iostream>

#include "../Types/type.hpp"
#include "../Tables/symbol_table.hpp"
#include "parameterlist.hpp"

extern SymbolTable* symbols;

class Procedure {

public:
    void declare();
    void call();
    std::map<std::string, Type*> params;
    int getStackSize() { return stacksize; }
    void declareParameters();
protected:
    ParameterList plist;
    int stacksize;
};

#endif