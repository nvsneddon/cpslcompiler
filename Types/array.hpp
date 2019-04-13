#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "type.hpp"
#include "simpletype.hpp"
#include "../Expressions/expression.hpp"
#include "../Expressions/memexpression.hpp"

class Array : public Type {
public:
    Array(int, int);
    Array(int, int, Type*);
    Array(int, int, std::string);
    Type* getCopyPtr();
    int size() { return hi - low + 1; }
    std::string getTypeAsString() { return "array"; }

    int getOffset(int);
private:
    Type* t;
    int low, hi;
};

#endif