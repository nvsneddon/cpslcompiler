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
    bool isref;
};

class ParameterList{
public:
    void addParameter(std::string n, Type* t);
    void addParameter(std::string n, Type* t, bool);
    int getSize();
    int getLength() { return plist.size(); }
    void saveParameters();
    void saveAsParameter(std::string n, Expression* e);
    void print(); 
    bool isReferenceAt(int x);
private:
    std::vector<Parameter> plist;
};

#endif