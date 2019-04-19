#include "functionlist.hpp"

void FunctionList::declareFunction(std::string n, Procedure* p){
    p->declare();
    currProcedure = p;
    functions.insert(std::make_pair(n, p));
}

FunctionList::~FunctionList(){
    for(auto it = functions.begin(); it != functions.end(); it++){
        delete it->second;
    }
}

RegExpression* FunctionList::callFunction(std::string n){
    auto it = functions.find(n);
    if(it != functions.end()){
        return it->second->call();
    }
    else{
        std::cerr << "Function " << n << " not defined in code.\n";
        throw "function error";
    }
}

RegExpression* FunctionList::callFunction(std::string n, ExpressionsList* exlist){
    auto it = functions.find(n);
    if(it != functions.end()){
        return it->second->call(exlist);

    }
    else{
        std::cerr << "Function " << n << " not defined in code.\n";
        throw "function error";
    }
}

bool FunctionList::isFunction(std::string fct){
    return true;
}