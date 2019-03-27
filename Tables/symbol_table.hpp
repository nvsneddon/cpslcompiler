#ifndef SYMBOL_TABLE_HPP
#define SYMBOL_TABLE_HPP 

#include <iostream>
#include <vector>
#include <map>
#include "expression.hpp"

class symbolTable{
    public:
    private:
        std::vector<std::map<std::string, int>> variables;    
};


#endif