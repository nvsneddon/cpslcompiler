#include "regexpression.hpp"

RegExpression::RegExpression(){
    reg = rtable->getNewRegister();
    expressionType = new Integer();
}

RegExpression::RegExpression(Type* t){
    reg = rtable->getNewRegister();
    expressionType = t;
}

RegExpression::RegExpression(std::string t){
    reg = rtable->getNewRegister();
    if(t == "integer"){
        expressionType = new Integer();
    }
    else if(t == "char"){
        expressionType = new Char();
    }
    else if(t == "string"){
        expressionType = new String();
    }
    else if(t == "boolean"){
        expressionType = new Boolean();
    }
}

RegExpression::~RegExpression(){
    rtable->addRegister(reg);
}

RegExpression* RegExpression::copyAsRegExpression(){
    RegExpression* returnexpr = new RegExpression(expressionType->getCopyPtr());
    std::cout << "move " << returnexpr->getRegister() << ", " << reg << std::endl;
    return returnexpr;
}

void RegExpression::write(){
    if(expressionType->getTypeAsString() == "integer"){
        std::cout << "li $v0, 1" << std::endl; 
    }
    else if(expressionType->getTypeAsString() == "char"){
        std::cout << "li $v0, 11" << std::endl; 
    }
    else if(expressionType->getTypeAsString() == "string"){
    }
    else if(expressionType->getTypeAsString() == "boolean"){
        std::cout << "li $v0, 1" << std::endl; 
    }
    std::cout << "move $a0, " << reg << std::endl;
    std::cout << "syscall\n";
}

Expression* RegExpression::add(Expression* other){
    if(dynamic_cast<Integer*>(expressionType) == NULL && dynamic_cast<Integer*>(other->getExpressionType()) == NULL) {
        throw "Wrong expression type";
    }   

    RegExpression* newreg = new RegExpression();
    RegExpression* otherreg = other->copyAsRegExpression();
    std::cout << "add " << newreg->getRegister() << ", " << reg << ", " << otherreg->getRegister() << std::endl;
    delete otherreg;
    return newreg;
}
Expression* RegExpression::sub(Expression* other) {
    if(dynamic_cast<Integer*>(expressionType) == NULL && dynamic_cast<Integer*>(other->getExpressionType()) == NULL) {
        throw "Wrong expression type";
    }   

    RegExpression* newreg = new RegExpression();
    RegExpression* otherreg = other->copyAsRegExpression();
    std::cout << "sub " << newreg->getRegister() << ", " << reg << ", " << otherreg->getRegister() << std::endl;
    delete otherreg;
    return newreg;
}
Expression* RegExpression::mult(Expression* other) {
    RegExpression* newreg = new RegExpression();
    RegExpression* otherreg = other->copyAsRegExpression();
    std::cout << "mult " << reg << ", " << otherreg->getRegister() << std::endl;
    std::cout << "mflo " << newreg->getRegister() << std::endl;
    delete otherreg;
    return newreg;
}
Expression* RegExpression::div(Expression* other) {
    RegExpression* newreg = new RegExpression();
    RegExpression* otherreg = other->copyAsRegExpression();
    std::cout << "div " << reg << ", " << otherreg->getRegister() << std::endl;
    std::cout << "mflo " << newreg->getRegister() << std::endl;
    delete otherreg;
    return newreg;
}
Expression* RegExpression::mod(Expression* other) {
    RegExpression* newreg = new RegExpression();
    RegExpression* otherreg = other->copyAsRegExpression();
    std::cout << "div " << reg << ", " << otherreg->getRegister() << std::endl;
    std::cout << "mfhi " << newreg->getRegister() << std::endl;
    delete otherreg;
    return newreg;
}
Expression* RegExpression::lt(Expression* other) {
    RegExpression* newreg = new RegExpression(new Boolean());
    RegExpression* otherreg = other->copyAsRegExpression();
    std::cout << "slt " << newreg->getRegister() << ", " << reg << ", " << otherreg->getRegister() << std::endl;
    delete otherreg;
    return newreg;
}
Expression* RegExpression::lte(Expression* other) {
    RegExpression* newreg = new RegExpression(new Boolean());
    RegExpression* otherreg = other->copyAsRegExpression();
    std::cout << "sle " << newreg->getRegister() << ", " << reg << ", " << otherreg->getRegister() << std::endl;
    delete otherreg;
    return newreg;
}
Expression* RegExpression::gt(Expression* other) {
    RegExpression* newreg = new RegExpression(new Boolean());
    RegExpression* otherreg = other->copyAsRegExpression();
    std::cout << "sgt " << newreg->getRegister() << ", " << reg << ", " << otherreg->getRegister() << std::endl;
    delete otherreg;
    return newreg;
}
Expression* RegExpression::gte(Expression* other) {
    RegExpression* newreg = new RegExpression(new Boolean());
    RegExpression* otherreg = other->copyAsRegExpression();
    std::cout << "sge " << newreg->getRegister() << ", " << reg << ", " << otherreg->getRegister() << std::endl;
    delete otherreg;
    return newreg;
}
Expression* RegExpression::ne(Expression* other) {
    RegExpression* newreg = new RegExpression(new Boolean());
    RegExpression* otherreg = other->copyAsRegExpression();
    std::cout << "sne " << newreg->getRegister() << ", " << reg << ", " << otherreg->getRegister() << std::endl;
    delete otherreg;
    return newreg;
}
Expression* RegExpression::eq(Expression* other) {
    RegExpression* newreg = new RegExpression(new Boolean());
    RegExpression* otherreg = other->copyAsRegExpression();
    std::cout << "seq " << newreg->getRegister() << ", " << reg << ", " << otherreg->getRegister() << std::endl;
    delete otherreg;
    return newreg;
}
Expression* RegExpression::andfun(Expression* other) {
    RegExpression* newreg = new RegExpression(new Boolean());
    RegExpression* otherreg = other->copyAsRegExpression();
    std::cout << "and " << newreg->getRegister() << ", " << reg << ", " << otherreg->getRegister() << std::endl;
    delete otherreg;
    return newreg;
}
Expression* RegExpression::orfun(Expression* other) {
    RegExpression* newreg = new RegExpression(new Boolean());
    RegExpression* otherreg = other->copyAsRegExpression();
    std::cout << "or " << newreg->getRegister() << ", " << reg << ", " << otherreg->getRegister() << std::endl;
    delete otherreg;
    return newreg;
}