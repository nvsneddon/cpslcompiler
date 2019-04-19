#include "function.hpp"
Function::Function(std::string n, Type* t) : Procedure(n) {
    returnsize = t->size();
    returnType = t;
}

Function::Function(std::string n, ParameterList* p, Type* t) : Procedure(n, p){
    returnsize = t->size();
    returnType = t;
}

void Function::storeExpression(Expression* e){
    RegExpression* r = e->copyAsRegExpression();
    std::cout << "sw " << r->getRegister() << ", " << stacksize << "($fp)" << std::endl;
    delete r;
}

RegExpression* Function::getExpression(){
    RegExpression* r = new RegExpression(returnType->getCopyPtr());
    std::cout << "lw " << r->getRegister() << ", " << stacksize << "($fp)" << std::endl;
    return r;
}