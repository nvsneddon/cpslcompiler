#include "procedure.hpp"

Procedure::Procedure(std::string n){
    name = n;
    stacksize = 0;
    localvarsize = 0;
}

Procedure::Procedure(std::string n, ParameterList* p){
    name = n;
    plist = p;
    localvarsize = 0;
    if(p == NULL)
        stacksize = 0;
    else
        stacksize = p->getSize();
}

void Procedure::declare() {
    symbols->startFunctionScope();
    std::cout << name << ":\n";
    if(plist != NULL)
        plist->saveParameters();
}

RegExpression* Procedure::call() {
    int sizeOffset = rtable->getUsedSize()*4+stacksize;
    std::cout << "addi $sp, $sp, -" << sizeOffset << std::endl;
    Write::comment("Spilling registers");
    rtable->spillregisters(stacksize);
    std::cout << "move $fp, $sp" << std::endl;
    std::cout << "jal " << name << std::endl;
	std::cout << "move $sp, $fp" << std::endl;
    Write::comment("unspilling registers");
    rtable->unspillregisters(stacksize);
    std::cout << "addi $sp, $sp, " << sizeOffset << std::endl;
    return NULL;
}

RegExpression* Procedure::call(ExpressionsList* e) {
    int sizeOffset = rtable->getUsedSize()*4+stacksize;
    int sizeCounter = 0;

    std::cout << "addi $sp, $sp, -" << sizeOffset << std::endl;
    Write::comment("Spilling registers");
    rtable->spillregisters(stacksize);
    std::cout << "move $fp, $sp" << std::endl;
    for(int i = 0; i < e->getSize(); i++){
        RegExpression* r = e->elist[i]->copyAsRegExpression();
        std::cout << "sw " << r->getRegister() << ", " << sizeCounter << "($sp)" << std::endl;
        sizeCounter += r->getExpressionType()->size();
        delete r;
    }
    std::cout << "jal " << name << std::endl;
	std::cout << "move $sp, $fp" << std::endl;
    Write::comment("unspilling registers");
    rtable->unspillregisters(stacksize);
    std::cout << "addi $sp, $sp, " << sizeOffset << std::endl;
    return NULL;
}

Procedure::~Procedure(){
    delete plist;
}