#include "procedure.hpp"

Procedure::Procedure(std::string n){
    name = n;
}

Procedure::Procedure(std::string n, ParameterList* p){
    name = n;
    plist = p;
}

void Procedure::declare() {
    symbols->startFunctionScope();
    std::cout << name << ":\n";
    plist->saveParameters();
}

Procedure::~Procedure(){
    delete plist;
}