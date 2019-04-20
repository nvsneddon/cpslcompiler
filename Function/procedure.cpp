#include "procedure.hpp"

Procedure::Procedure(std::string n){
    name = n;
    stacksize = 0;
    localvarsize = 0;
    plist = NULL;
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
    if(e->getSize() != plist->getLength()){
        std::cerr << "Wrong number of parameter arguments. " << plist->getSize() << " expected, " << e->getSize() << " found" << std::endl;
        throw "fit";
    }
    for(int i = 0; i < e->getSize(); i++){
        if(plist->isReferenceAt(i)){
            RegExpression* temp = new RegExpression();
            MemExpression* mem = dynamic_cast<MemExpression*>(e->elist[i]);
            if(mem == NULL){
                std::cerr << "We have a problem here\n";
                throw "fit";
            }
            std::cout << "la " << temp->getRegister() << ", " << mem->getOffset() << "(" << mem->getPtrReference() << ")" << std::endl;
            std::cout << "sw " << temp->getRegister() << ", " << sizeCounter << "($sp)" << std::endl;
            sizeCounter += mem->getExpressionType()->size();
            delete temp;
        }
        else{
            RegExpression* r = e->elist[i]->copyAsRegExpression();
            std::cout << "sw " << r->getRegister() << ", " << sizeCounter << "($sp)" << std::endl;
            sizeCounter += r->getExpressionType()->size();
            delete r;
        }
    }
    std::cout << "move $fp, $sp" << std::endl;
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