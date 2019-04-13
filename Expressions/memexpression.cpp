#include "memexpression.hpp"


MemExpression::MemExpression() : MemExpression(-1, "$gp", new Integer(), true) {}

MemExpression::MemExpression(Type* t) : MemExpression(-1, "$gp", t, true) {}
MemExpression::MemExpression(std::string p, Type* t) : MemExpression(-1, p, t, true) {}

MemExpression::MemExpression(int o) 
: MemExpression(o, "$gp", new Integer(), false) {
    //offset = o;
    //ptr = "$gp";
    //expressionType = new Integer();
    //temporary = false;
}

MemExpression::MemExpression(int o, std::string r) 
: MemExpression(0, r, new Integer(), false) {
    //offset = o;
    //ptr = r;
    //expressionType = new Integer();
    //temporary = false;
}

MemExpression::MemExpression(int o, Type* t) 
: MemExpression(o, "$gp", t, false){
    //offset = o;
    //ptr = "$gp";
    //expressionType = t;
    //temporary = false;
}

MemExpression::MemExpression(int o, Type* t, bool farray) 
: MemExpression(o, "$gp", t, farray) {
    //offset = o;
    //ptr = "$gp";
    //expressionType = t;
    //temporary = farray;
}

MemExpression::MemExpression(int o, std::string r, Type* t)
: MemExpression(o, r, t, false) {}

MemExpression::MemExpression(int o, std::string r, Type* t, bool farray) {
    offset = o;
    ptr = r;
    expressionType = t;
    temporary = farray;    
}

MemExpression::~MemExpression(){
    
}

RegExpression* MemExpression::copyAsRegExpression() {
    RegExpression* myreg = new RegExpression(expressionType->getCopyPtr());
    std::cout << "lw " << myreg->getRegister() << ", " << offset << "(" << ptr << ")" << std::endl;
    return myreg;
} 

void MemExpression::write(){
    RegExpression* myreg = copyAsRegExpression();
    myreg->write();
    delete myreg;
}

void MemExpression::storeExpression(Expression* expr){
    RegExpression* regexpression = expr->copyAsRegExpression();
    std::cout << "sw " << regexpression->getRegister() << ", " << offset << "(" << ptr << ")" << std::endl;
    delete regexpression;
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
    Expression* returnexpr = reg->mult(other);
    delete reg;
    return returnexpr;
} 
Expression* MemExpression::div(Expression* other) {
    RegExpression* reg = copyAsRegExpression();
    Expression* returnexpr = reg->div(other);
    delete reg;
    return returnexpr;
} 
Expression* MemExpression::mod(Expression* other) {
    RegExpression* reg = copyAsRegExpression();
    Expression* returnexpr = reg->mod(other);
    delete reg;
    return returnexpr;
} 
Expression* MemExpression::lt(Expression* other) {
    RegExpression* reg = copyAsRegExpression();
    Expression* returnexpr = reg->lt(other);
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
