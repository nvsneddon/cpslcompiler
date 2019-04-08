#ifndef EXPRESSION_HPP 
#define EXPRESSION_HPP

#include <string>
#include "../Types/type.hpp"
#include "../Types/simpletype.hpp"

class Expression{
public:
    Expression() { }
private:
    Type* expressionType;
};

class ConstExpression : public Expression{
public:
    ConstExpression(int e) { element = e; }
    ConstExpression() { element = 0; }
    int getElement() { return element; }
private:
    int element;
};

class RegExpression : public Expression{
public:
    RegExpression();
    RegExpression(ConstExpression c);
private:
    std::string reg;
};

class MemExpression : public Expression{
public:
    MemExpression();
private:
    std::string reg;
    int offset;
};

#endif