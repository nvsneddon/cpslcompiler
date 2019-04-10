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

ConstExpression::~ConstExpression(){
    delete expressionType;
}

void ConstExpression::write(){
    if(expressionType->getTypeAsString() == "integer"){
        std::cout << "li $v0 1" << std::endl; 
    }
    else if(expressionType->getTypeAsString() == "char"){
        std::cout << "li $v0 11" << std::endl; 
    }
    else if(expressionType->getTypeAsString() == "string"){

    }
    else if(expressionType->getTypeAsString() == "boolean"){

    }
    std::cout << "li $a0, " << element << std::endl;
    std::cout << "syscall\n";
}

RegExpression* ConstExpression::copyAsRegExpression(){
    RegExpression* returnexpr = new RegExpression();
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
        return new ConstExpression(element - con->getElement());
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
    if(ConstExpression* con = dynamic_cast<ConstExpression*>(other)){
        if(dynamic_cast<Integer*>(expressionType) == NULL && dynamic_cast<Integer*>(other->getExpressionType()) == NULL) {
            throw "Wrong expression type";
        }   
        return new ConstExpression(element / con->getElement());
    }
    return new ConstExpression(15);
}


//Mod functions
Expression* ConstExpression::mod(Expression* other){
    if(ConstExpression* con = dynamic_cast<ConstExpression*>(other)){
        if(dynamic_cast<Integer*>(expressionType) == NULL && dynamic_cast<Integer*>(other->getExpressionType()) == NULL) {
            throw "Wrong expression type";
        }   
        return new ConstExpression(element % con->getElement());
    }
    return new ConstExpression(15);
}


Expression* ConstExpression::lt(Expression* other){
    bool result;
    if(ConstExpression* con = dynamic_cast<ConstExpression*>(other)){
        result = element < con->getElement();
    }
    return new ConstExpression(result ? 1 : 0, new Boolean());
}


Expression* ConstExpression::lte(Expression* other){
    bool result;
    if(ConstExpression* con = dynamic_cast<ConstExpression*>(other)){
        result = element <= con->getElement();
    }
    return new ConstExpression(result ? 1 : 0, new Boolean());
}

Expression* ConstExpression::gt(Expression* other){
    bool result;
    if(ConstExpression* con = dynamic_cast<ConstExpression*>(other)){
        result = element > con->getElement();
    }
    return new ConstExpression(result ? 1 : 0, new Boolean());
}

Expression* ConstExpression::gte(Expression* other){
    bool result;
    if(ConstExpression* con = dynamic_cast<ConstExpression*>(other)){
        result = element >= con->getElement();
    }
    return new ConstExpression(result ? 1 : 0, new Boolean());
}

Expression* ConstExpression::ne(Expression* other){
    bool result;
    if(ConstExpression* con = dynamic_cast<ConstExpression*>(other)){
        result = element != con->getElement();
    }
    return new ConstExpression(result ? 1 : 0, new Boolean());
}

Expression* ConstExpression::eq(Expression* other){
    bool result;
    if(ConstExpression* con = dynamic_cast<ConstExpression*>(other)){
        result = element == con->getElement();
    }
    return new ConstExpression(result ? 1 : 0, new Boolean());
}

Expression* ConstExpression::andfun(Expression* other){
    bool result;
    if(ConstExpression* con = dynamic_cast<ConstExpression*>(other)){
        result = element && con->getElement();
    }
    return new ConstExpression(result ? 1 : 0, new Boolean());
}

Expression* ConstExpression::orfun(Expression* other){
    bool result;
    if(ConstExpression* con = dynamic_cast<ConstExpression*>(other)){
        result = element || con->getElement();
    }
    return new ConstExpression(result ? 1 : 0, new Boolean());
}
