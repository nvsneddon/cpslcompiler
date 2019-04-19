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

void FunctionList::callFunction(std::string n){
    auto it = functions.find(n);
    if(it != functions.end()){
        it->second->call();
    }
    else{
        std::cerr << "Function " << n << " not defined in code.\n";
        throw "function error";
    }
}

void FunctionList::callFunction(std::string n, ExpressionsList* exlist){
    auto it = functions.find(n);
    if(it != functions.end()){
        it->second->call(exlist);
    }
    else{
        std::cerr << "Function " << n << " not defined in code.\n";
        throw "function error";
    }
}