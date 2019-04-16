#ifndef SYMBOL_TABLE_HPP
#define SYMBOL_TABLE_HPP 

#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include "../Expressions/expression.hpp"
#include "../Expressions/constexpression.hpp"
#include "../Expressions/memexpression.hpp"
#include "../Types/simpletype.hpp"
#include "../Types/type.hpp"


class SymbolTable{
    public:
        SymbolTable(); 
        ~SymbolTable();
        MemExpression* findVariable(std::string myvar);
        ConstExpression* findConstant(std::string myvar);
        Type* findType(std::string mytype);
        void declareVariable(std::string, Type*);
        void declareVariable(std::string, Type*, bool);
        void declareForVariable(std::string, Type*);
        void declareConstant(std::string, ConstExpression*);
        void declareType(std::string, Type*);
        void printStringLabels();
        void addScope();
        void removeScope();
        void removeForVar();
        std::string getReferencePointer();
        int appendString(std::string str);
        void printStats();
        MemExpression* getForVariable();
        static int getOffset(int);
    private:
        std::deque<std::map<std::string, MemExpression*>> variables;    
        std::map<std::string, ConstExpression*> constants;
        std::vector<std::map<std::string, std::string>> toPrint;
        std::vector<std::string> stringVariables;
        std::map<std::string, Type*> types;
        std::deque<MemExpression*> forvariables;
};


#endif