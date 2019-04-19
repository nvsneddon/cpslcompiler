#ifndef PARAMETERLIST_HPP
#define PARAMETERLIST_HPP

#include <vector>
#include <string>
#include <iostream>

#include "../Tables/symbol_table.hpp"
#include "../Types/type.hpp"

extern SymbolTable* symbols;

struct Parameter{
    std::string name;
    Type* type;
};

class ParameterList{
public:
    void addParameter(std::string n, Type* t);
    int getSize();
    void saveParameters();
    void print(); 
private:
    std::vector<Parameter> plist;
};

#endif