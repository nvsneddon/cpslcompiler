#ifndef EXPRESSION_HPP 
#define EXPRESSION_HPP

#include <string>
#include "../Types/type.hpp"
#include "../Types/simpletype.hpp"

class RegExpression;
class Expression{
public:
    virtual Expression* add(Expression* other) = 0;
    virtual Expression* sub(Expression* other) = 0;
    virtual Expression* mult(Expression* other) = 0;
    virtual Expression* div(Expression* other) = 0;
    virtual Expression* mod(Expression* other) = 0;
    virtual Expression* lt(Expression* other) = 0;
    virtual Expression* lte(Expression* other) = 0;
    virtual Expression* gt(Expression* other) = 0;
    virtual Expression* gte(Expression* other) = 0;
    virtual Expression* ne(Expression* other) = 0;
    virtual Expression* eq(Expression* other) = 0;
    virtual Expression* andfun(Expression* other) = 0;
    virtual Expression* orfun(Expression* other) = 0;

    virtual RegExpression* copyAsRegExpression() = 0;
    //virtual void write() = 0;

    Type* getExpressionType() { return expressionType; }
protected:
    Type* expressionType;
};


#endif
