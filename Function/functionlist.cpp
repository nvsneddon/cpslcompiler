#include "functionlist.hpp"

void FunctionList::declareFunction(std::string n, Procedure* p){
    p->declare();
    functions.insert(std::make_pair(n, p));
}

FunctionList::~FunctionList(){
    for(auto it = functions.begin(); it != functions.end(); it++){
        delete it->second;
    }
}