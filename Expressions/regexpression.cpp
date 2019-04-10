#include "regexpression.hpp"

RegExpression::RegExpression(){
    reg = rtable->getRegister();
}

RegExpression::~RegExpression(){
    rtable->addRegister(reg);
}


Expression* RegExpression::add(Expression* other){
    RegExpression* newreg = new RegExpression();
    if(ConstExpression* c = dynamic_cast<ConstExpression*>(other)){
        std::cout << "addi " << newreg->getRegister() << ", " << this->getRegister() << ", " << c->getElement() << std::endl;;
    }
    else if(RegExpression* r = dynamic_cast<RegExpression*>(other)){
        std::cout << "add " << newreg->getRegister() << ", " << this->getRegister() << ", " << r->getRegister() << std::endl;
    }
    return newreg;
}
Expression* RegExpression::sub(Expression* other) {
    RegExpression* newreg = new RegExpression();
    if(ConstExpression* c = dynamic_cast<ConstExpression*>(other)){
        std::cout << "subi " << newreg->getRegister() << ", " << this->getRegister() << ", " << c->getElement() << std::endl;
    }
    else if(RegExpression* r = dynamic_cast<RegExpression*>(other)){
        std::cout << "sub " << newreg->getRegister() << ", " << this->getRegister() << ", " << r->getRegister() << std::endl;
    }
    return newreg;
}
Expression* RegExpression::mult(Expression* other) {
    RegExpression* newreg = new RegExpression();
    if(ConstExpression* c = dynamic_cast<ConstExpression*>(other)){
        std::string tempreg = rtable->getRegister();
        std::cout << "li " << tempreg << ", " << c->getElement() << std::endl;
        std::cout << "mult " << this->getRegister() << ", " << tempreg << std::endl;
        std::cout << "mflo " << newreg->getRegister() << std::endl;
        rtable->addRegister(tempreg);
    }
    else if(RegExpression* r = dynamic_cast<RegExpression*>(other)){
        std::cout << "mult " << newreg->getRegister() << ", " << this->getRegister() << ", " << r->getRegister() << std::endl;
    }
    return newreg;
}
Expression* RegExpression::div(Expression* other) {
    RegExpression* newreg = new RegExpression();
    if(ConstExpression* c = dynamic_cast<ConstExpression*>(other)){
        std::string tempreg = rtable->getRegister();
        std::cout << "li " << tempreg << ", " << c->getElement() << std::endl;
        std::cout << "div " << ", " << this->getRegister() << ", " << tempreg << std::endl;
        std::cout << "mflo " << newreg->getRegister() << std::endl;
        rtable->addRegister(tempreg);
    }
    else if(RegExpression* r = dynamic_cast<RegExpression*>(other)){
        std::cout << "div " << newreg->getRegister() << ", " << this->getRegister() << ", " << r->getRegister() << std::endl;
    }
    return newreg;
}
Expression* RegExpression::mod(Expression* other) {
    RegExpression* newreg = new RegExpression();
    if(ConstExpression* c = dynamic_cast<ConstExpression*>(other)){
        std::cout << "addi " << newreg->getRegister() << ", " << this->getRegister() << ", " << c->getElement() << std::endl;
    }
    else if(RegExpression* r = dynamic_cast<RegExpression*>(other)){
        std::cout << "add " << newreg->getRegister() << ", " << this->getRegister() << ", " << r->getRegister() << std::endl;
    }
    return newreg;
}
Expression* RegExpression::lt(Expression* other) {
    RegExpression* newreg = new RegExpression();
    if(ConstExpression* c = dynamic_cast<ConstExpression*>(other)){
        std::cout << "addi " << newreg->getRegister() << ", " << this->getRegister() << ", " << c->getElement() << std::endl;
    }
    else if(RegExpression* r = dynamic_cast<RegExpression*>(other)){
        std::cout << "add " << newreg->getRegister() << ", " << this->getRegister() << ", " << r->getRegister() << std::endl;
    }
    return newreg;
}
Expression* RegExpression::lte(Expression* other) {
    RegExpression* newreg = new RegExpression();
    if(ConstExpression* c = dynamic_cast<ConstExpression*>(other)){
        std::cout << "addi " << newreg->getRegister() << ", " << this->getRegister() << ", " << c->getElement() << std::endl;
    }
    else if(RegExpression* r = dynamic_cast<RegExpression*>(other)){
        std::cout << "add " << newreg->getRegister() << ", " << this->getRegister() << ", " << r->getRegister() << std::endl;
    }
    return newreg;
}
Expression* RegExpression::gt(Expression* other) {
    RegExpression* newreg = new RegExpression();
    if(ConstExpression* c = dynamic_cast<ConstExpression*>(other)){
        std::cout << "addi " << newreg->getRegister() << ", " << this->getRegister() << ", " << c->getElement() << std::endl;
    }
    else if(RegExpression* r = dynamic_cast<RegExpression*>(other)){
        std::cout << "add " << newreg->getRegister() << ", " << this->getRegister() << ", " << r->getRegister() << std::endl;
    }
    return newreg;
}
Expression* RegExpression::gte(Expression* other) {
    RegExpression* newreg = new RegExpression();
    if(ConstExpression* c = dynamic_cast<ConstExpression*>(other)){
        std::cout << "addi " << newreg->getRegister() << ", " << this->getRegister() << ", " << c->getElement() << std::endl;
    }
    else if(RegExpression* r = dynamic_cast<RegExpression*>(other)){
        std::cout << "add " << newreg->getRegister() << ", " << this->getRegister() << ", " << r->getRegister() << std::endl;
    }
    return newreg;
}
Expression* RegExpression::ne(Expression* other) {
    RegExpression* newreg = new RegExpression();
    if(ConstExpression* c = dynamic_cast<ConstExpression*>(other)){
        std::cout << "addi " << newreg->getRegister() << ", " << this->getRegister() << ", " << c->getElement() << std::endl;
    }
    else if(RegExpression* r = dynamic_cast<RegExpression*>(other)){
        std::cout << "add " << newreg->getRegister() << ", " << this->getRegister() << ", " << r->getRegister() << std::endl;
    }
    return newreg;
}
Expression* RegExpression::eq(Expression* other) {
    RegExpression* newreg = new RegExpression();
    if(ConstExpression* c = dynamic_cast<ConstExpression*>(other)){
        std::cout << "addi " << newreg->getRegister() << ", " << this->getRegister() << ", " << c->getElement() << std::endl;
    }
    else if(RegExpression* r = dynamic_cast<RegExpression*>(other)){
        std::cout << "add " << newreg->getRegister() << ", " << this->getRegister() << ", " << r->getRegister() << std::endl;
    }
    return newreg;
}
Expression* RegExpression::andfun(Expression* other) {
    RegExpression* newreg = new RegExpression();
    if(ConstExpression* c = dynamic_cast<ConstExpression*>(other)){
        std::cout << "addi " << newreg->getRegister() << ", " << this->getRegister() << ", " << c->getElement() << std::endl;
    }
    else if(RegExpression* r = dynamic_cast<RegExpression*>(other)){
        std::cout << "add " << newreg->getRegister() << ", " << this->getRegister() << ", " << r->getRegister() << std::endl;
    }
    return newreg;
}
Expression* RegExpression::orfun(Expression* other) {
    RegExpression* newreg = new RegExpression();
    if(ConstExpression* c = dynamic_cast<ConstExpression*>(other)){
        std::cout << "addi " << newreg->getRegister() << ", " << this->getRegister() << ", " << c->getElement() << std::endl;
    }
    else if(RegExpression* r = dynamic_cast<RegExpression*>(other)){
        std::cout << "add " << newreg->getRegister() << ", " << this->getRegister() << ", " << r->getRegister() << std::endl;
    }
    return newreg;
}