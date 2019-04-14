#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <vector>
#include <iostream>

#include "type.hpp"
#include "simpletype.hpp"
#include "../Tables/symbol_table.hpp"
#include "../Expressions/expression.hpp"
#include "../Expressions/memexpression.hpp"
#include "../Expressions/tempmemexpression.hpp"

extern SymbolTable* symbols;

class Array : public Type {
public:
    Array(int l, int h);
    Array(int l, int h, Type*);
    Array(int l, int h, std::string);
    Type* getCopyPtr();
    int size() { return numofelements * arrayType->size(); }
    std::string getTypeAsString() { return "array of " + arrayType->getTypeAsString(); }
    MemExpression* getExpressionAt(int, std::string, int);
    MemExpression* getExpressionAt(int, std::string, Expression*);
    MemExpression* getExpressionAt(int, std::string, int, bool);
    MemExpression* getExpressionAt(int, std::string, Expression*, bool);
    Type* getType() { return arrayType; }
private:
    Type* arrayType;
    int low, hi, numofelements;
};

#endif