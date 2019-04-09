#ifndef MEMEXPRESSION_HPP 
#define MEMEXPRESSION_HPP 

#include "expression.hpp"

class MemExpression : public Expression{
public:
    MemExpression();
    Expression* add(Expression* other);
private:
    std::string reg;
    int offset;
};

#endif