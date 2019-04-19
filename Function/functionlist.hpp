#ifndef FUNCTIONLIST_HPP
#define FUNCTIONLIST_HPP

#include "procedure.hpp"
#include "function.hpp"

class FunctionList {
public:
    FunctionList(){}
    ~FunctionList();
    void declareFunction(std::string n, Procedure* p);
    void callFunction(std::string fct);
    void callFunction(std::string fct, ExpressionsList* exlist);

private:
    std::map<std::string, Procedure*> functions; 
};

#endif