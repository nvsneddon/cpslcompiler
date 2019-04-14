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
    MemExpression(int, Type*, bool);
    MemExpression(int, std::string, Type*, bool);
    MemExpression(int, Type*, bool, bool);
    MemExpression(int, std::string, Type*, bool, bool);
    //MemExpression(RegExpression*);
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
    
    virtual RegExpression* copyAsRegExpression();
    virtual void storeExpression(Expression* expr);
    void write();

    int getOffset(){ return offset; }
    std::string getPtrReference() { return ptr; }
    virtual bool isTemporary(){ return temporary; };
    bool constant(){ return isconstant; }

    virtual ~MemExpression();
protected:
    MemExpression();
    MemExpression(Type*);
    MemExpression(std::string, Type*);
    MemExpression(Type*, bool);
    MemExpression(std::string, Type*, bool);
    std::string ptr;
    bool temporary;
    bool isconstant;
    int offset;
};

#endif