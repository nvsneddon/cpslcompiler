#ifndef EXPRESSION_HPP 
#define EXPRESSION_HPP

#include <string>
#include "../Types/type.hpp"
#include "../Types/simpletype.hpp"

class Expression{
public:
    Expression() { }
    virtual Expression* add(Expression* other) = 0;
    virtual Expression* sub(Expression* other) = 0;
    virtual Expression* mult(Expression* other) = 0;
    virtual Expression* div(Expression* other) = 0;
    virtual Expression* mod(Expression* other) = 0;
    virtual Expression* lt(Expression* other) = 0;
    virtual Expression* lte(Expression* other) = 0;
    Type* getExpressionType() { return expressionType; }
protected:
    Type* expressionType;
};

class ConstExpression : public Expression{
public:
    ConstExpression(int e);
    ConstExpression(int e, Type* t); 

    Expression* add(Expression* other);
    Expression* sub(Expression* other);
    Expression* mult(Expression* other);
    Expression* div(Expression* other);
    Expression* mod(Expression* other);
    Expression* lt(Expression* other);
    Expression* lte(Expression* other);

    int getElement() { return element; }
    ~ConstExpression();
private:
    int element;
};

class RegExpression : public Expression{
public:
    RegExpression();
    RegExpression(ConstExpression c);
    Expression* add(Expression* other);
private:
    std::string reg;
};

class MemExpression : public Expression{
public:
    MemExpression();
    Expression* add(Expression* other);
private:
    std::string reg;
    int offset;
};

#endif