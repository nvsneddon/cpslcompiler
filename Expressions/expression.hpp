#ifndef EXPRESSION_HPP 
#define EXPRESSION_HPP

#include <string>
#include "../Types/type.hpp"

class Expression{
    public:
        Expression(int expr, std::string theType);
        int getExpression() { return e; }
    private:
        Type* type;
        int e;
};

#endif