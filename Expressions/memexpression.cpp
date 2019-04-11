#include "memexpression.hpp"

MemExpression::MemExpression(){
    offset = 0;
    reg = "$gp";
    expressionType = new Integer();
}

MemExpression::MemExpression(int o){
    offset = o;
    reg = "$gp";
    expressionType = new Integer();
}

MemExpression::MemExpression(int o, std::string r){
    offset = o;
    reg = r;
    expressionType = new Integer();
}

MemExpression::MemExpression(int o, Type* t){
    offset = o;
    reg = "$gp";
    expressionType = t;
}

MemExpression::MemExpression(int o, std::string r, Type* t){
    offset = o;
    reg = r;
    expressionType = t;
}

RegExpression* MemExpression::copyAsRegExpression() {
    return NULL;
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
