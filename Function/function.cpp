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
    int sizeOffset = rtable->getUsedSize()*4+stacksize+returnsize;
    std::cout << "addi $sp, $sp, -" << sizeOffset << std::endl;
    Write::comment("Spilling registers");
    rtable->spillregisters(stacksize + returnsize);
    std::cout << "move $fp, $sp" << std::endl;
    std::cout << "jal " << name << std::endl;
    Write::comment("unspilling registers");
    rtable->unspillregisters(stacksize + returnsize);
    RegExpression* returnexpr = getExpression();
    std::cerr << "localvarsize is " << localvarsize << std::endl;
    std::cout << "addi $sp, $sp, " << sizeOffset + localvarsize << std::endl;
    return returnexpr;
}

RegExpression* Function::call(ExpressionsList* e){
    int sizeOffset = rtable->getUsedSize()*4+stacksize+returnsize;
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
    Write::comment("unspilling registers");
    rtable->unspillregisters(stacksize + returnsize);
    RegExpression* returnexpr = getExpression();
    std::cerr << "localvarsize is " << localvarsize << std::endl;
    std::cout << "addi $sp, $sp, " << sizeOffset + localvarsize << std::endl;
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