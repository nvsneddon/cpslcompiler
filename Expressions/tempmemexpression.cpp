#include "tempmemexpression.hpp"

TempMemExpression::TempMemExpression(RegExpression* reg) : offsetreg(reg){}
TempMemExpression::TempMemExpression(RegExpression* reg, Type* t) : MemExpression(t), offsetreg(reg){}
TempMemExpression::TempMemExpression(RegExpression* reg, Type* t, bool isconst) : MemExpression(t, isconst), offsetreg(reg){}

RegExpression* TempMemExpression::copyAsRegExpression() {
    RegExpression* myreg = new RegExpression(expressionType->getCopyPtr());
    std::cout << "lw " << myreg->getRegister() << ", " << "(" << offsetreg->getRegister() << ")" << std::endl;
    return myreg;
} 

void TempMemExpression::storeExpression(Expression* expr){
    RegExpression* regexpression = expr->copyAsRegExpression();
    Write::comment("In the store expression from tempmemexpression");
    std::cout << "sw " << regexpression->getRegister() << ", " << "(" << offsetreg->getRegister() << ")" << std::endl;
    delete regexpression;
}

TempMemExpression::~TempMemExpression(){
    delete offsetreg;
}