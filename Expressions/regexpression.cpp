#include "regexpression.hpp"

RegExpression::RegExpression(){
    reg = rtable->getRegister();
    expressionType = new Integer();
}

RegExpression::RegExpression(Type* t){
    reg = rtable->getRegister();
    expressionType = t;
}

RegExpression::RegExpression(std::string t){
    reg = rtable->getRegister();
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
    RegExpression* returnexpr = new RegExpression();
    std::cout << "move " << returnexpr->getRegister() << ", " << reg << std::endl;
    return returnexpr;
}

void RegExpression::write(){
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
    std::cout << "mv $a0, " << reg << std::endl;
    std::cout << "syscall\n";
}

Expression* RegExpression::add(Expression* other){
    if(dynamic_cast<Integer*>(expressionType) == NULL && dynamic_cast<Integer*>(other->getExpressionType()) == NULL) {
        throw "Wrong expression type";
    }   

    RegExpression* newreg = new RegExpression();
    std::cerr << "Register of newreg in add function " << newreg->getRegister() << std::endl;
    RegExpression* thisone = copyAsRegExpression();
    std::cerr << "Register of thisone in add function " << thisone->getRegister() << std::endl;
    RegExpression* thatone = other->copyAsRegExpression();
    std::cerr << "Register of thatone in add function " << thatone->getRegister() << std::endl;
    std::cout << "add " << newreg->getRegister() << ", " << thisone->getRegister() << ", " << thatone->getRegister() << std::endl;
    delete thisone;
    delete thatone;
    return newreg;
}
Expression* RegExpression::sub(Expression* other) {
    if(dynamic_cast<Integer*>(expressionType) == NULL && dynamic_cast<Integer*>(other->getExpressionType()) == NULL) {
        throw "Wrong expression type";
    }   

    RegExpression* newreg = new RegExpression();
    RegExpression* thisone = copyAsRegExpression();
    RegExpression* thatone = other->copyAsRegExpression();
    std::cout << "sub " << newreg->getRegister() << ", " << thisone->getRegister() << ", " << thatone->getRegister() << std::endl;
    delete thisone;
    delete thatone;
    return newreg;
}
Expression* RegExpression::mult(Expression* other) {
    RegExpression* newreg = new RegExpression();
    //if(ConstExpression* c = dynamic_cast<ConstExpression*>(other)){
    //    std::string tempreg = rtable->getRegister();
    //    std::cout << "li " << tempreg << ", " << c->getElement() << std::endl;
    //    std::cout << "mult " << this->getRegister() << ", " << tempreg << std::endl;
    //    std::cout << "mflo " << newreg->getRegister() << std::endl;
    //    rtable->addRegister(tempreg);
    //}
    //else if(RegExpression* r = dynamic_cast<RegExpression*>(other)){
    //    std::cout << "mult " << newreg->getRegister() << ", " << this->getRegister() << ", " << r->getRegister() << std::endl;
    //}
    return newreg;
}
Expression* RegExpression::div(Expression* other) {
    RegExpression* newreg = new RegExpression();
    //if(ConstExpression* c = dynamic_cast<ConstExpression*>(other)){
    //    std::string tempreg = rtable->getRegister();
    //    std::cout << "li " << tempreg << ", " << c->getElement() << std::endl;
    //    std::cout << "div " << ", " << this->getRegister() << ", " << tempreg << std::endl;
    //    std::cout << "mflo " << newreg->getRegister() << std::endl;
    //    rtable->addRegister(tempreg);
    //}
    //else if(RegExpression* r = dynamic_cast<RegExpression*>(other)){
    //    std::cout << "div " << newreg->getRegister() << ", " << this->getRegister() << ", " << r->getRegister() << std::endl;
    //}
    return newreg;
}
Expression* RegExpression::mod(Expression* other) {
    RegExpression* newreg = new RegExpression();
    //if(ConstExpression* c = dynamic_cast<ConstExpression*>(other)){
    //    std::cout << "addi " << newreg->getRegister() << ", " << this->getRegister() << ", " << c->getElement() << std::endl;
    //}
    //else if(RegExpression* r = dynamic_cast<RegExpression*>(other)){
    //    std::cout << "add " << newreg->getRegister() << ", " << this->getRegister() << ", " << r->getRegister() << std::endl;
    //}
    return newreg;
}
Expression* RegExpression::lt(Expression* other) {
    RegExpression* newreg = new RegExpression();
    //if(ConstExpression* c = dynamic_cast<ConstExpression*>(other)){
    //    std::cout << "addi " << newreg->getRegister() << ", " << this->getRegister() << ", " << c->getElement() << std::endl;
    //}
    //else if(RegExpression* r = dynamic_cast<RegExpression*>(other)){
    //    std::cout << "add " << newreg->getRegister() << ", " << this->getRegister() << ", " << r->getRegister() << std::endl;
    //}
    return newreg;
}
Expression* RegExpression::lte(Expression* other) {
    RegExpression* newreg = new RegExpression();
    //if(ConstExpression* c = dynamic_cast<ConstExpression*>(other)){
    //    std::cout << "addi " << newreg->getRegister() << ", " << this->getRegister() << ", " << c->getElement() << std::endl;
    //}
    //else if(RegExpression* r = dynamic_cast<RegExpression*>(other)){
    //    std::cout << "add " << newreg->getRegister() << ", " << this->getRegister() << ", " << r->getRegister() << std::endl;
    //}
    return newreg;
}
Expression* RegExpression::gt(Expression* other) {
    RegExpression* newreg = new RegExpression();
    //if(ConstExpression* c = dynamic_cast<ConstExpression*>(other)){
    //    std::cout << "addi " << newreg->getRegister() << ", " << this->getRegister() << ", " << c->getElement() << std::endl;
    //}
    //else if(RegExpression* r = dynamic_cast<RegExpression*>(other)){
    //    std::cout << "add " << newreg->getRegister() << ", " << this->getRegister() << ", " << r->getRegister() << std::endl;
    //}
    return newreg;
}
Expression* RegExpression::gte(Expression* other) {
    RegExpression* newreg = new RegExpression();
    //if(ConstExpression* c = dynamic_cast<ConstExpression*>(other)){
    //    std::cout << "addi " << newreg->getRegister() << ", " << this->getRegister() << ", " << c->getElement() << std::endl;
    //}
    //else if(RegExpression* r = dynamic_cast<RegExpression*>(other)){
    //    std::cout << "add " << newreg->getRegister() << ", " << this->getRegister() << ", " << r->getRegister() << std::endl;
    //}
    return newreg;
}
Expression* RegExpression::ne(Expression* other) {
    RegExpression* newreg = new RegExpression();
    //if(ConstExpression* c = dynamic_cast<ConstExpression*>(other)){
    //    std::cout << "addi " << newreg->getRegister() << ", " << this->getRegister() << ", " << c->getElement() << std::endl;
    //}
    //else if(RegExpression* r = dynamic_cast<RegExpression*>(other)){
    //    std::cout << "add " << newreg->getRegister() << ", " << this->getRegister() << ", " << r->getRegister() << std::endl;
    //}
    return newreg;
}
Expression* RegExpression::eq(Expression* other) {
    RegExpression* newreg = new RegExpression();
    //if(ConstExpression* c = dynamic_cast<ConstExpression*>(other)){
    //    std::cout << "addi " << newreg->getRegister() << ", " << this->getRegister() << ", " << c->getElement() << std::endl;
    //}
    //else if(RegExpression* r = dynamic_cast<RegExpression*>(other)){
    //    std::cout << "add " << newreg->getRegister() << ", " << this->getRegister() << ", " << r->getRegister() << std::endl;
    //}
    return newreg;
}
Expression* RegExpression::andfun(Expression* other) {
    RegExpression* newreg = new RegExpression();
    //if(ConstExpression* c = dynamic_cast<ConstExpression*>(other)){
    //    std::cout << "addi " << newreg->getRegister() << ", " << this->getRegister() << ", " << c->getElement() << std::endl;
    //}
    //else if(RegExpression* r = dynamic_cast<RegExpression*>(other)){
    //    std::cout << "add " << newreg->getRegister() << ", " << this->getRegister() << ", " << r->getRegister() << std::endl;
    //}
    return newreg;
}
Expression* RegExpression::orfun(Expression* other) {
    RegExpression* newreg = new RegExpression();
    //if(ConstExpression* c = dynamic_cast<ConstExpression*>(other)){
    //    std::cout << "addi " << newreg->getRegister() << ", " << this->getRegister() << ", " << c->getElement() << std::endl;
    //}
    //else if(RegExpression* r = dynamic_cast<RegExpression*>(other)){
    //    std::cout << "add " << newreg->getRegister() << ", " << this->getRegister() << ", " << r->getRegister() << std::endl;
    //}
    return newreg;
}