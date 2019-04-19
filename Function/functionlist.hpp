#ifndef FUNCTIONLIST_HPP
#define FUNCTIONLIST_HPP

#include "procedure.hpp"
#include "function.hpp"

class FunctionList {
public:
    FunctionList(){}
    ~FunctionList();
    void declareFunction(std::string n, Procedure* p);
    RegExpression* callFunction(std::string fct);
    RegExpression* callFunction(std::string fct, ExpressionsList* exlist);
    void saveReturnValue(Expression* e);
    bool isFunction(std::string fct);
    void markAsCurrProcedure(Procedure* p) { currProcedure = p; }
    void removeCurrProcedure() { currProcedure = NULL; }
    Procedure* getCurrProcedure() { return currProcedure; }
private:
    std::map<std::string, Procedure*> functions; 
    Procedure* currProcedure;
};

#endif