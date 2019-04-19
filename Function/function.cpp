#include "function.hpp"
Function::Function(std::string n, Type* t) : Procedure(n) {
    returnsize = t->size();
    returnType = t;
}

Function::Function(std::string n, ParameterList* p, Type* t) : Procedure(n, p){
    returnsize = t->size();
    returnType = t;
}

RegExpression* Function::call(){
    int sizeOffset = rtable->getUsedSize()*4+stacksize;
    std::cout << "addi $sp, $sp, -" << sizeOffset << std::endl;
    Write::comment("Spilling registers");
    rtable->spillregisters(stacksize);
    std::cout << "move $fp, $sp" << std::endl;
    std::cout << "jal " << name << std::endl;
    rtable->unspillregisters(stacksize);
    RegExpression* returnexpr = getExpression();
    Write::comment("unspilling registers");
    std::cout << "addi $sp, $sp, " << sizeOffset << std::endl;
    return returnexpr;
}

RegExpression* Function::call(ExpressionsList* e){
    int sizeOffset = rtable->getUsedSize()*4+stacksize;
    int sizeCounter = 0;

    std::cout << "addi $sp, $sp, -" << sizeOffset << std::endl;
    Write::comment("Spilling registers");
    rtable->spillregisters(stacksize + returnsize);
    std::cout << "move $fp, $sp" << std::endl;
    for(int i = 0; i < e->getSize(); i++){
        RegExpression* r = e->elist[i]->copyAsRegExpression();
        std::cout << "sw " << r->getRegister() << ", " << sizeCounter << "($sp)" << std::endl;
        sizeCounter += r->getExpressionType()->size();
        delete r;
    }
    std::cout << "jal " << name << std::endl;
    rtable->unspillregisters(stacksize + returnsize);
    Write::comment("unspilling registers");
    RegExpression* returnexpr = getExpression();
    std::cout << "addi $sp, $sp, " << sizeOffset << std::endl;
    return returnexpr;
}


void Function::storeExpression(Expression* e){
    RegExpression* r = e->copyAsRegExpression();
    std::cout << "sw " << r->getRegister() << ", " << stacksize << "($fp)" << std::endl;
    delete r;
}

RegExpression* Function::getExpression(){
    RegExpression* r = new RegExpression(returnType->getCopyPtr());
    Write::comment("hweufhrug");
    std::cout << "lw " << r->getRegister() << ", " << stacksize << "($sp)" << std::endl;
    return r;
}