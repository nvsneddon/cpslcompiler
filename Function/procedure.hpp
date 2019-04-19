#ifndef PROCEDURE_HPP
#define PROCEDURE_HPP

#include <map>
#include <iostream>

#include "../Types/type.hpp"
#include "parameterlist.hpp"
#include "../Tables/symbol_table.hpp"
#include "../Tables/reg_table.hpp"
#include "../Expressions/expressionslist.hpp"

extern SymbolTable* symbols;
extern RegTable* rtable;

class Procedure {

public:
    Procedure(std::string);
    Procedure(std::string, ParameterList* plist);
    virtual ~Procedure();
    void declare(); 
    virtual RegExpression* call();
    virtual RegExpression* call(ExpressionsList* e);
    std::map<std::string, Type*> params;
    virtual int getStackSize() { return stacksize; }
    void declareParameters();
protected:
    std::string name;
    ParameterList* plist;
    int stacksize;
};

#endif