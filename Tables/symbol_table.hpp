#ifndef SYMBOL_TABLE_HPP
#define SYMBOL_TABLE_HPP 

#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include "../Expressions/expression.hpp"
#include "../Expressions/constexpression.hpp"
#include "../Types/simpletype.hpp"


class SymbolTable{
    public:
        SymbolTable(); 
        ~SymbolTable();
        void addVariable(std::string, Expression*);
        Expression* findVariable(std::string myvar);
        void printStringLabels();
        void addScope();
        void removeScope();
        std::string getReferencePointer();
        int appendString(std::string str);
        void printStats();
        static int getOffset(int);
    private:
        std::deque<std::map<std::string, Expression*>> variables;    
        std::vector<std::map<std::string, std::string>> toPrint;
        std::vector<std::string> stringVariables;
};


#endif