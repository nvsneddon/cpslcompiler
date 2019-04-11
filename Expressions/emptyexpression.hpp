#ifndef EMPTY_EXPRESSION_HPP
#define EMPTY_EXPRESSION_HPP
#include "expression.hpp"

class EmptyExpression : public Expression {
public:
    EmptyExpression();
    EmptyExpression(Type*);
    Expression* add(Expression* other) { throw "Not Initialized"; }
    Expression* sub(Expression* other) { throw "Not Initialized"; }
    Expression* mult(Expression* other) { throw "Not Initialized"; }
    Expression* div(Expression* other) { throw "Not Initialized"; }
    Expression* mod(Expression* other) { throw "Not Initialized"; }
    Expression* lt(Expression* other) { throw "Not Initialized"; }
    Expression* lte(Expression* other) { throw "Not Initialized"; }
    Expression* gt(Expression* other) { throw "Not Initialized"; }
    Expression* gte(Expression* other) { throw "Not Initialized"; }
    Expression* ne(Expression* other) { throw "Not Initialized"; }
    Expression* eq(Expression* other) { throw "Not Initialized"; }
    Expression* andfun(Expression* other) { throw "Not Initialized"; }
    Expression* orfun(Expression* other) { throw "Not Initialized"; }
    RegExpression* copyAsRegExpression() { throw "Not Initialized"; }
    void write() { throw "Not Initialized"; }
};

#endif