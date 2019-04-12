#include "constexpression.hpp"
#include <iostream>
#include <typeinfo>

ConstExpression::ConstExpression(int e){
    expressionType = new Integer();
    element = e;
}

ConstExpression::ConstExpression(int e, Type* t){
    expressionType = t;
    element = e;
}

ConstExpression::ConstExpression(int e, std::string t){
    element = e;
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

ConstExpression::~ConstExpression(){}

void ConstExpression::write(){
    if(expressionType->getTypeAsString() == "integer"){
        std::cout << "li $v0, 1" << std::endl; 
        std::cout << "li $a0, " << element << std::endl;
        std::cout << "syscall\n";
    }
    else if(expressionType->getTypeAsString() == "char"){
        std::cout << "li $v0, 11" << std::endl; 
        std::cout << "li $a0, " << element << std::endl;
        std::cout << "syscall\n";
    }
    else if(expressionType->getTypeAsString() == "string"){
        std::cout << "li $v0, 4" << std::endl; 
        std::cout << "la $a0, string" << element << std::endl;
        std::cout << "syscall\n";
    }
    else if(expressionType->getTypeAsString() == "boolean"){
        std::cout << "li $v0, 4" << std::endl; 
        std::cout << "la $a0, string" << element << std::endl;
        std::cout << "syscall\n";
    }
}

RegExpression* ConstExpression::copyAsRegExpression(){
    RegExpression* returnexpr = new RegExpression(expressionType->getCopyPtr());
    std::cout << "li " << returnexpr->getRegister() << ", " << element << std::endl;
    return returnexpr;
}
    
//Add functions
Expression* ConstExpression::add(Expression* other){
    if(dynamic_cast<Integer*>(expressionType) == NULL && dynamic_cast<Integer*>(other->getExpressionType()) == NULL) {
        throw "Wrong expression type";
    }   
    if(ConstExpression* con = dynamic_cast<ConstExpression*>(other)){
        return new ConstExpression(element + con->getElement());
    }
    RegExpression* otherexpr = other->copyAsRegExpression();
    RegExpression* returnexpr = new RegExpression(new Integer());
    std::cout << "addi " << returnexpr->getRegister() << ", " << otherexpr->getRegister() << ", " << element << std::endl;
    delete otherexpr;
    return returnexpr;
}


//Subtraction functions
Expression* ConstExpression::sub(Expression* other){
    if(dynamic_cast<Integer*>(expressionType) == NULL && dynamic_cast<Integer*>(other->getExpressionType()) == NULL) {
        throw "Wrong expression type";
    }   
    if(ConstExpression* con = dynamic_cast<ConstExpression*>(other)){
        return new ConstExpression(element - con->getElement());
    }
    RegExpression* thisexpr = copyAsRegExpression();
    RegExpression* otherexpr = other->copyAsRegExpression();
    RegExpression* returnexpr = new RegExpression(new Integer());
    std::cout << "sub " << returnexpr->getRegister() << ", " << thisexpr->getRegister() << ", " << otherexpr->getRegister() << std::endl;
    delete thisexpr;
    delete otherexpr;
    return returnexpr;
}


//Multiplication functions
Expression* ConstExpression::mult(Expression* other){
    if(dynamic_cast<Integer*>(expressionType) == NULL && dynamic_cast<Integer*>(other->getExpressionType()) == NULL) {
        throw "Wrong expression type";
    }   
    if(ConstExpression* con = dynamic_cast<ConstExpression*>(other)){
        return new ConstExpression(element * con->getElement());
    }
    RegExpression* thisexpr = copyAsRegExpression();
    RegExpression* otherexpr = other->copyAsRegExpression();
    RegExpression* returnexpr = new RegExpression(new Integer());
    std::cout << "mult " << thisexpr->getRegister() << ", " << otherexpr->getRegister() << std::endl;
    std::cout << "mflo " << returnexpr->getRegister() << std::endl;
    delete thisexpr;
    delete otherexpr;
    return returnexpr;
}

//Division functions
Expression* ConstExpression::div(Expression* other){
    if(dynamic_cast<Integer*>(expressionType) == NULL && dynamic_cast<Integer*>(other->getExpressionType()) == NULL) {
        throw "Wrong expression type";
    }   
    if(ConstExpression* con = dynamic_cast<ConstExpression*>(other)){
        return new ConstExpression(element / con->getElement());
    }
    RegExpression* thisexpr = copyAsRegExpression();
    RegExpression* otherexpr = other->copyAsRegExpression();
    RegExpression* returnexpr = new RegExpression(new Integer());
    std::cout << "div " << thisexpr->getRegister() << ", " << otherexpr->getRegister() << std::endl;
    std::cout << "mflo " << returnexpr->getRegister() << std::endl;
    delete thisexpr;
    delete otherexpr;
    return returnexpr;
}


//Mod functions
Expression* ConstExpression::mod(Expression* other){
    if(dynamic_cast<Integer*>(expressionType) == NULL && dynamic_cast<Integer*>(other->getExpressionType()) == NULL) {
        throw "Wrong expression type";
    }   
    if(ConstExpression* con = dynamic_cast<ConstExpression*>(other)){
        return new ConstExpression(element % con->getElement());
    }
    RegExpression* thisexpr = copyAsRegExpression();
    RegExpression* otherexpr = other->copyAsRegExpression();
    RegExpression* returnexpr = new RegExpression(new Integer());
    std::cout << "div " << thisexpr->getRegister() << ", " << otherexpr->getRegister() << std::endl;
    std::cout << "mfhi " << returnexpr->getRegister() << std::endl;
    delete thisexpr;
    delete otherexpr;
    return new ConstExpression(15);
}


Expression* ConstExpression::lt(Expression* other){
    bool result;
    if(ConstExpression* con = dynamic_cast<ConstExpression*>(other)){
        result = element < con->getElement();
        return new ConstExpression(result ? 1 : 0, new Boolean());
    }
    RegExpression* thisreg = copyAsRegExpression();
    RegExpression* newreg = new RegExpression(new Boolean());
    RegExpression* otherreg = other->copyAsRegExpression();
    std::cout << "slt " << newreg->getRegister() << ", " << thisreg->getRegister() << ", " << otherreg->getRegister() << std::endl;
    delete otherreg;
    delete thisreg;
    return newreg;
}


Expression* ConstExpression::lte(Expression* other){
    bool result;
    if(ConstExpression* con = dynamic_cast<ConstExpression*>(other)){
        result = element <= con->getElement();
        return new ConstExpression(result ? 1 : 0, new Boolean());
    }
    RegExpression* thisreg = copyAsRegExpression();
    RegExpression* newreg = new RegExpression(new Boolean());
    RegExpression* otherreg = other->copyAsRegExpression();
    std::cout << "sle " << newreg->getRegister() << ", " << thisreg->getRegister() << ", " << otherreg->getRegister() << std::endl;
    delete otherreg;
    delete thisreg;
    return newreg;
}

Expression* ConstExpression::gt(Expression* other){
    bool result;
    if(ConstExpression* con = dynamic_cast<ConstExpression*>(other)){
        result = element > con->getElement();
        return new ConstExpression(result ? 1 : 0, new Boolean());
    }
    RegExpression* thisreg = copyAsRegExpression();
    RegExpression* newreg = new RegExpression(new Boolean());
    RegExpression* otherreg = other->copyAsRegExpression();
    std::cout << "sgt " << newreg->getRegister() << ", " << thisreg->getRegister() << ", " << otherreg->getRegister() << std::endl;
    delete otherreg;
    delete thisreg;
    return newreg;
}

Expression* ConstExpression::gte(Expression* other){
    bool result;
    if(ConstExpression* con = dynamic_cast<ConstExpression*>(other)){
        result = element >= con->getElement();
        return new ConstExpression(result ? 1 : 0, new Boolean());
    }
    RegExpression* thisreg = copyAsRegExpression();
    RegExpression* newreg = new RegExpression(new Boolean());
    RegExpression* otherreg = other->copyAsRegExpression();
    std::cout << "sge " << newreg->getRegister() << ", " << thisreg->getRegister() << ", " << otherreg->getRegister() << std::endl;
    delete otherreg;
    delete thisreg;
    return newreg;
}

Expression* ConstExpression::ne(Expression* other){
    bool result;
    if(ConstExpression* con = dynamic_cast<ConstExpression*>(other)){
        result = element != con->getElement();
        return new ConstExpression(result ? 1 : 0, new Boolean());
    }
    RegExpression* thisreg = copyAsRegExpression();
    RegExpression* newreg = new RegExpression(new Boolean());
    RegExpression* otherreg = other->copyAsRegExpression();
    std::cout << "sne " << newreg->getRegister() << ", " << thisreg->getRegister() << ", " << otherreg->getRegister() << std::endl;
    delete otherreg;
    delete thisreg;
    return newreg;
}

Expression* ConstExpression::eq(Expression* other){
    bool result;
    if(ConstExpression* con = dynamic_cast<ConstExpression*>(other)){
        result = element == con->getElement();
        return new ConstExpression(result ? 1 : 0, new Boolean());
    }
    RegExpression* thisreg = copyAsRegExpression();
    RegExpression* newreg = new RegExpression(new Boolean());
    RegExpression* otherreg = other->copyAsRegExpression();
    std::cout << "seq " << newreg->getRegister() << ", " << thisreg->getRegister() << ", " << otherreg->getRegister() << std::endl;
    delete otherreg;
    delete thisreg;
    return newreg;
}

Expression* ConstExpression::andfun(Expression* other){
    bool result;
    if(ConstExpression* con = dynamic_cast<ConstExpression*>(other)){
        result = element && con->getElement() == 1;
        return new ConstExpression(result ? 1 : 0, new Boolean());
    }
    RegExpression* thisreg = copyAsRegExpression();
    RegExpression* newreg = new RegExpression(new Boolean());
    RegExpression* otherreg = other->copyAsRegExpression();
    std::cout << "and " << newreg->getRegister() << ", " << thisreg->getRegister() << ", " << otherreg->getRegister() << std::endl;
    delete otherreg;
    delete thisreg;
    return newreg;
}

Expression* ConstExpression::orfun(Expression* other){
    bool result;
    if(ConstExpression* con = dynamic_cast<ConstExpression*>(other)){
        result = element || con->getElement() == 1;
        return new ConstExpression(result ? 1 : 0, new Boolean());
    }
    RegExpression* thisreg = copyAsRegExpression();
    RegExpression* newreg = new RegExpression(new Boolean());
    RegExpression* otherreg = other->copyAsRegExpression();
    std::cout << "or " << newreg->getRegister() << ", " << thisreg->getRegister() << ", " << otherreg->getRegister() << std::endl;
    delete otherreg;
    delete thisreg;
    return newreg;
}
