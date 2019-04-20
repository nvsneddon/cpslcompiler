#ifndef REFEXPRESSION_HPP
#define REFEXPRESSION_HPP

#include "memexpression.hpp"

class RefExpression : public MemExpression {
public:
    RefExpression(int, std::string, Type*);
    RefExpression(int, Type*);
    RegExpression* copyAsRegExpression();
    void storeExpression(Expression*);
};

#endif