#ifndef EXPRESSIONLIST_HPP
#define EXPRESSIONLIST_HPP

#include <vector>
#include "expression.hpp"
#include "memexpression.hpp"
#include "constexpression.hpp"
#include <iostream>

class ExpressionsList{
public:
    ExpressionsList();
    ~ExpressionsList();
    void add(Expression* e) { elist.push_back(e);};
    void write();
private:
    std::vector<Expression*> elist;
};

#endif