#ifndef EXPRESSIONLIST_HPP
#define EXPRESSIONLIST_HPP

#include <vector>
#include "expression.hpp"

class ExpressionsList{
public:
    ExpressionsList();
    ~ExpressionsList();
    void add(Type* t);
private:
    std::vector<Expression*> elist;
};

#endif