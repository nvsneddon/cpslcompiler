#ifndef MEMEXPRESSION_HPP 
#define MEMEXPRESSION_HPP 

#include "expression.hpp"

class MemExpression : public Expression{
public:
    MemExpression();
    Expression* add(Expression* other);
    Expression* sub(Expression* other);
    Expression* mult(Expression* other);
    Expression* div(Expression* other);
    Expression* mod(Expression* other);
    Expression* lt(Expression* other);
    Expression* lte(Expression* other);
    Expression* gt(Expression* other);
    Expression* gte(Expression* other);
    Expression* ne(Expression* other);
    Expression* eq(Expression* other);
    Expression* andfun(Expression* other);
    Expression* orfun(Expression* other);
private:
    std::string reg;
    int offset;
};

#endif