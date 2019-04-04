#ifndef EXPRESSION_HPP 
#define EXPRESSION_HPP

#include <string>
#include "../Types/type.hpp"

class Expression{
    public:
        Expression(Type* tpe) { expr = tpe; }
    private:
        Type* expr;
};

#endif