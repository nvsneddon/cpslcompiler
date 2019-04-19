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

void ParameterList::saveParameters(){
    for(auto it = plist.begin(); it != plist.end(); it++){
        symbols->declareVariable(it->name, it->type->getCopyPtr());
    }
}

void ParameterList::print() {
    for(auto it = plist.begin(); it != plist.end(); it++){
        std::cerr << it->name << '\t' << it->type->getTypeAsString() << std::endl;
    }
}

void ParameterList::saveAsParameter(std::string n, Expression* e){

}