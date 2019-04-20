#ifndef REFEXPRESSION_HPP
#define REFEXPRESSION_HPP

#include "memexpression.hpp"

class RefExpression : public MemExpression {
    RefExpression(int, std::string, Type*);
    RefExpression(int, Type*);
};

#endif