#include "memexpression.hpp"


MemExpression::MemExpression(int o){
    offset = o;
    ptr = "$gp";
    expressionType = new Integer();
}

MemExpression::MemExpression(int o, std::string r){
    offset = o;
    ptr = r;
    expressionType = new Integer();
}

MemExpression::MemExpression(int o, Type* t){
    offset = o;
    ptr = "$gp";
    expressionType = t;
}

MemExpression::MemExpression(int o, std::string r, Type* t){
    offset = o;
    ptr = r;
    expressionType = t;
}

RegExpression* MemExpression::copyAsRegExpression() {
    RegExpression* myreg = new RegExpression(expressionType->getCopyPtr());
    std::cout << "lw " << myreg->getRegister() << ", " << offset << "(" << ptr << ")" << std::endl;
    return myreg;
} 

void MemExpression::write(){
    RegExpression* myreg = new RegExpression(expressionType->getCopyPtr());
    myreg->write();
    delete myreg;
}

void MemExpression::storeExpression(Expression* expr){
    RegExpression* reg = expr->copyAsRegExpression();
    std::cout << "sw " << reg->getRegister() << ", " << offset << "(" << ptr << ")" << std::endl;
    delete reg;
}

Expression* MemExpression::add(Expression* other) {
    RegExpression* reg = copyAsRegExpression();
    Expression* returnexpr = reg->add(other);
    delete reg;
    return returnexpr;
} 
Expression* MemExpression::sub(Expression* other) {
    RegExpression* reg = copyAsRegExpression();
    Expression* returnexpr = reg->sub(other);
    delete reg;
    return returnexpr;
} 
Expression* MemExpression::mult(Expression* other) {
    RegExpression* reg = copyAsRegExpression();
    Expression* returnexpr = reg->sub(other);
    delete reg;
    return returnexpr;
} 
Expression* MemExpression::div(Expression* other) {
    RegExpression* reg = copyAsRegExpression();
    Expression* returnexpr = reg->mult(other);
    delete reg;
    return returnexpr;
} 
Expression* MemExpression::mod(Expression* other) {
    RegExpression* reg = copyAsRegExpression();
    Expression* returnexpr = reg->div(other);
    delete reg;
    return returnexpr;
} 
Expression* MemExpression::lt(Expression* other) {
    RegExpression* reg = copyAsRegExpression();
    Expression* returnexpr = reg->mod(other);
    delete reg;
    return returnexpr;
} 
Expression* MemExpression::lte(Expression* other) {
    RegExpression* reg = copyAsRegExpression();
    Expression* returnexpr = reg->lte(other);
    delete reg;
    return returnexpr;
} 
Expression* MemExpression::gt(Expression* other) {
    RegExpression* reg = copyAsRegExpression();
    Expression* returnexpr = reg->gt(other);
    delete reg;
    return returnexpr;
} 
Expression* MemExpression::gte(Expression* other) {
    RegExpression* reg = copyAsRegExpression();
    Expression* returnexpr = reg->gte(other);
    delete reg;
    return returnexpr;
} 
Expression* MemExpression::ne(Expression* other) {
    RegExpression* reg = copyAsRegExpression();
    Expression* returnexpr = reg->ne(other);
    delete reg;
    return returnexpr;
} 
Expression* MemExpression::eq(Expression* other) {
    RegExpression* reg = copyAsRegExpression();
    Expression* returnexpr = reg->eq(other);
    delete reg;
    return returnexpr;
} 
Expression* MemExpression::andfun(Expression* other) {
    RegExpression* reg = copyAsRegExpression();
    Expression* returnexpr = reg->andfun(other);
    delete reg;
    return returnexpr;
} 
Expression* MemExpression::orfun(Expression* other) {
    RegExpression* reg = copyAsRegExpression();
    Expression* returnexpr = reg->orfun(other);
    delete reg;
    return returnexpr;
} 
