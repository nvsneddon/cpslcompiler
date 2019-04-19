#ifndef FUNCTIONLIST_HPP
#define FUNCTIONLIST_HPP

#include <vector>
#include "procedure.hpp"
#include "function.hpp"

class FunctionList {
public:
    FunctionList(){}
    ~FunctionList();
    void declareFunction(std::string n, Procedure* p);


private:
    std::map<std::string, Procedure*> functions; 
};

#endif