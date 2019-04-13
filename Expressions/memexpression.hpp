#ifndef MEMEXPRESSION_HPP 
#define MEMEXPRESSION_HPP 

#include "expression.hpp"
#include "regexpression.hpp"
#include <iostream>

class MemExpression : public Expression{
public:
    MemExpression(int);
    MemExpression(int, std::string);
    MemExpression(int, Type*);
    MemExpression(int, std::string, Type*);
    MemExpression(RegExpression*);
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
    
    RegExpression* copyAsRegExpression();
    void storeExpression(Expression* expr);
    void write();

    int getOffset(){ return offset; }

    ~MemExpression();
private:
    std::string ptr;
    int offset;
};

#endif