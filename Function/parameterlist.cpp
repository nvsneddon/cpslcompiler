#include "parameterlist.hpp"

void ParameterList::addParameter(std::string n, Type* t){
    Parameter p;
    p.name = n;
    p.type = t->getCopyPtr();
    plist.push_back(p);
}

int ParameterList::getSize(){
    int size = 0;
    for(auto it = plist.begin(); it != plist.end(); it++){
        size += it->type->size();
    }
    return size;
}