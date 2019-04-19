#include "procedure.hpp"

Procedure::Procedure(std::string n){
    name = n;
    stacksize = 0;
}

Procedure::Procedure(std::string n, ParameterList* p){
    name = n;
    plist = p;
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

void Procedure::call() {
    rtable->spillregisters(stacksize);
    std::cout << "jal " << name << std::endl;
    rtable->unspillregisters(stacksize);
}

Procedure::~Procedure(){
    delete plist;
}