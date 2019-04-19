#include "function.hpp"
Function::Function(std::string n, Type* t) : Procedure(n) {
    //name = n;
    //stacksize = t->size();
    stacksize += t->size();
    returnType = t;
}

Function::Function(std::string n, ParameterList* p, Type* t) : Procedure(n) {
    //name = n;
    //plist = p;
    //if(p == NULL)
    //    stacksize = t->size();
    //else
    //    stacksize = t->size() + p->getSize();
    stacksize += t->size();
    returnType = t;
}