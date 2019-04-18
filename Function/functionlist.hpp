#ifndef FUNCTIONLIST_HPP
#define FUNCTIONLIST_HPP

#include <vector>
#include "procedure.hpp"
#include "function.hpp"

class FunctionList {
public:
    void declareFunction();

private:
    std::map<std::string, Procedure*> functions; 
};

#endif