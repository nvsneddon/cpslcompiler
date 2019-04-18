#include "parameterlist.hpp"

void ParameterList::addParameter(std::string n, Type* t){
    Parameter p;
    p.name = n;
    p.type = t->getCopyPtr();
    plist.push_back(p);
}