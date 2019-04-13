#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <vector>
#include <iostream>

#include "type.hpp"
#include "simpletype.hpp"
#include "../Tables/symbol_table.hpp"
#include "../Expressions/expression.hpp"
#include "../Expressions/memexpression.hpp"

extern SymbolTable* symbols;

class Array : public Type {
public:
    Array(int l, int h);
    Array(int l, int h, Type*);
    Array(int l, int h, std::string);
    Type* getCopyPtr();
    int size() { return sizenum; }
    std::string getTypeAsString() { return "array of " + arrayType->getTypeAsString(); }
    RegExpression* getExpressionAt(int);
    int getOffset(int, int);
    Type* getType() { return arrayType; }
private:
    Type* arrayType;
    int low, hi, sizenum;
};

#endif