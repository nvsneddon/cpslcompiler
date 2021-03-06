#ifndef TEMPMEMEXPRESSION_HPP
#define TEMPMEMEXPRESSION_HPP

#include "memexpression.hpp"

class TempMemExpression : public MemExpression {
public:
    TempMemExpression(RegExpression*);
    TempMemExpression(RegExpression*, Type*);
    TempMemExpression(RegExpression*, Type*, bool);

    RegExpression* copyAsRegExpression();
    bool isTemporary(){ return true; };
    void storeExpression(Expression* expr);

    ~TempMemExpression();
private:
    RegExpression* offsetreg;
};

#endif