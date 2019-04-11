#include "memexpression.hpp"

MemExpression::MemExpression(){
    offset = SymbolTable::getOffset(4);
    ptr = symbols->getReferencePointer();
    expressionType = new Integer();
}

MemExpression::MemExpression(Type* t){
    offset = SymbolTable::getOffset(t->size());
    ptr = symbols->getReferencePointer();
    expressionType = t;
}

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
    return NULL;
} 

void MemExpression::write(){

}

void MemExpression::storeExpression(Expression* expr){
    RegExpression* reg = expr->copyAsRegExpression();
    std::cout << "sw " << reg->getRegister() << ", " << offset << "(" << ptr << ")" << std::endl;
    delete reg;
}

Expression* MemExpression::add(Expression* other) {
    return NULL;
} 
Expression* MemExpression::sub(Expression* other) {
    return NULL;
} 
Expression* MemExpression::mult(Expression* other) {
    return NULL;
} 
Expression* MemExpression::div(Expression* other) {
    return NULL;
} 
Expression* MemExpression::mod(Expression* other) {
    return NULL;
} 
Expression* MemExpression::lt(Expression* other) {
    return NULL;
} 
Expression* MemExpression::lte(Expression* other) {
    return NULL;
} 
Expression* MemExpression::gt(Expression* other) {
    return NULL;
} 
Expression* MemExpression::gte(Expression* other) {
    return NULL;
} 
Expression* MemExpression::ne(Expression* other) {
    return NULL;
} 
Expression* MemExpression::eq(Expression* other) {
    return NULL;
} 
Expression* MemExpression::andfun(Expression* other) {
    return NULL;
} 
Expression* MemExpression::orfun(Expression* other) {
    return NULL;
} 
