#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "type.hpp"
#include "../Expressions/expression.hpp"
#include "../Expressions/memexpression.hpp"

class Array : public Type{
private:
    Type* t;
    int lowbound, upbound;
};

#endif