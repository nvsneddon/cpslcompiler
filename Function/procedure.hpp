#ifndef PROCEDURE_HPP
#define PROCEDURE_HPP

#include <map>
#include <iostream>

#include "../Types/type.hpp"
#include "../Tables/symbol_table.hpp"

extern SymbolTable* symbols;

struct Parameter{
    std::string name;
    Type* type;
};

class Procedure {

public:
    void declare();
    void call();
    std::map<std::string, Type*> params;
    int getStackSize() { return stacksize; }
    void declareParameters();
protected:
    std::vector<Parameter> parameterlist;
    int stacksize;
};

#endif