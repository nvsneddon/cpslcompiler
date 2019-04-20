#include "refexpression.hpp"

RefExpression::RefExpression(int o, std::string p, Type* t) : MemExpression(o, p, t) {}

RefExpression::RefExpression(int o, Type* t) : MemExpression(o, "$fp", t) {}

RegExpression* RefExpression::copyAsRegExpression(){
    RegExpression* myreg = new RegExpression(expressionType->getCopyPtr());
    Write::comment("This is where we load the reference");
    std::cout << "lw " << myreg->getRegister() << ", " << offset << "(" << ptr << ")" << std::endl;
    std::cout << "lw " << myreg->getRegister() << ", " << "(" << myreg->getRegister() << ")" << std::endl;
    return myreg;
}

void RefExpression::storeExpression(Expression* expr){
    RegExpression* addressreg = new RegExpression();
    RegExpression* regexpression = expr->copyAsRegExpression();
    Write::comment("This is where we store the reference");
    std::cout << "lw " << addressreg->getRegister() << ", " << offset << "(" << ptr << ")" << std::endl;
    std::cout << "sw " << regexpression->getRegister() << ", " << "(" << addressreg->getRegister() << ")" << std::endl;
    delete regexpression;
    delete addressreg;
}