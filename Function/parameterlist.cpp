#include "parameterlist.hpp"

void ParameterList::addParameter(std::string n, Type* t, bool ref){
    Parameter p;
    p.name = n;
    p.type = t;
    p.isref = ref;
    plist.push_back(p);
}

void ParameterList::addParameter(std::string n, Type* t){
    ParameterList::addParameter(n, t, false);
}

bool ParameterList::isReferenceAt(int x){
    return plist[x].isref;
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
        if(it->isref){
            symbols->declareRefVariable(it->name, it->type->getCopyPtr());
        }
        else {
            symbols->declareVariable(it->name, it->type->getCopyPtr());
        }
    }
}

void ParameterList::print() {
    for(auto it = plist.begin(); it != plist.end(); it++){
        std::cerr << it->name << '\t' << it->type->getTypeAsString() << std::endl;
    }
}

void ParameterList::saveAsParameter(std::string n, Expression* e){
    std::cerr << "The save as parameter is used, but it's not doing anything." << std::endl;
}