
#ifndef REG_EXPRESSION_HPP
#define REG_EXPRESSION_HPP
#include <iostream>
#include "expression.hpp"
#include "constexpression.hpp"
#include "../Tables/reg_table.hpp"

extern RegTable* rtable;

class RegExpression : public Expression{
public:
    RegExpression();
    ~RegExpression();
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

    std::string getRegister(){ return reg; }
private:
    std::string reg;
};

#endif