#include "procedure.hpp"

Procedure::Procedure(std::string n){
    name = n;
}

Procedure::Procedure(std::string n, ParameterList* p){
    name = n;
    plist = p;
}

Procedure::~Procedure(){
    delete plist;
}