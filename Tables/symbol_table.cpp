#include "symbol_table.hpp"

SymbolTable::SymbolTable(){
    addScope(); 
    refPointers.push("$gp");
}

SymbolTable::~SymbolTable(){
    for(int i = 0; i < variables.size(); i++){
        for (auto it = variables[i].begin(); it != variables[i].end(); it++ ){
            delete it->second;
        }
    }
}

void SymbolTable::startFunctionScope(){
    addScope();
    refPointers.push("$fp");
}

void SymbolTable::startFunctionScope(std::map<std::string, Type*> params){
    startFunctionScope();
    for(auto it = params.begin(); it != params.end(); it++){
        declareVariable(it->first, it->second->getCopyPtr());
    }
}

std::string SymbolTable::getReferencePointer(){
    return refPointers.top();
}

void SymbolTable::declareVariable(std::string varname, Type* t, bool forvar){
    auto it = constants.find(varname);
    if(it != constants.end() && findVariable(varname) != NULL){
        std::cerr << "Cannot declare a variable again\n";
        throw "error";
    }
    MemExpression* m = new MemExpression(getOffset(t->size()), getReferencePointer(), t);
    if(forvar)
        forvariables.push_front(m);
    variables[0].insert(std::make_pair(varname, m));
}

void SymbolTable::declareVariable(std::string varname, Type* t){
    declareVariable(varname, t, false);
}

void SymbolTable::declareForVariable(std::string varname, Type* t){
    declareVariable(varname, t, true);
}

void SymbolTable::declareConstant(std::string varname, ConstExpression* ex){
    constants.insert(std::make_pair(varname, ex));
}

void SymbolTable::declareType(std::string name, Type* t){
    types.insert(std::make_pair(name, t));
}
Type* SymbolTable::findType(std::string mytype){
    auto it = types.find(mytype);
    if(it != types.end()){
        return it->second->getCopyPtr();
    }
    return NULL;
}

void SymbolTable::printStats(){
    for(int i = 0; i < variables.size(); i++){
        std::cerr << "This is " << i << std::endl;
        for (auto it = variables[i].begin(); it != variables[i].end(); it++ ){
            std::cerr << it->first << std::endl;
        }
        std::cerr << "Done with " << i << ". Onto the next.\n";
    }
    std::cerr << "We are finished\n";
}

ConstExpression* SymbolTable::findConstant(std::string myvar){
    auto constit = constants.find(myvar);
    if (constit != constants.end()){
        return new ConstExpression(constit->second->getElement(), constit->second->getExpressionType());
    }
    return NULL;
}

MemExpression* SymbolTable::findVariable(std::string myvar){
    for(int i = 0; i < variables.size(); i++){
        auto it = variables[i].find(myvar);
        if (it != variables[i].end()){
            return it->second;
        }
    }
    return NULL;
}

void SymbolTable::addScope(){
    std::map<std::string, MemExpression*> newmap;
    variables.push_front(newmap);
    offsets.push_front(0);
}

MemExpression* SymbolTable::getForVariable(){
    return forvariables[0];
}

void SymbolTable::removeScope(){
    if(variables.size() == 1){
        std::cerr << "Cannot remove global scope\n";
        throw "Attempted to delete global scope";
    }
    
    for (auto it = variables[0].begin(); it != variables[0].end(); it++ ){
        delete it->second;
    }
    variables.pop_front();
    refPointers.pop();
    offsets.pop_front();
}

void SymbolTable::removeForVar(){
    forvariables.pop_front();
}

int SymbolTable::appendString(std::string str){
    int returnvalue = stringVariables.size();
    stringVariables.push_back(str);
    return returnvalue;
}

void SymbolTable::printStringLabels(){
    std::cout << ".data" << std::endl;
    for(int i = 0; i < stringVariables.size() ; i++){
        std::cout << "stringlabel" << i << ": " << stringVariables[i] << std::endl;
    }
}


int SymbolTable::getOffset(int size){
    int returnvalue = offsets[0];
    offsets[0] += size;
    return returnvalue;
    //static int offset = 0;
    //int returnvalue = offset;
    //offset += size;
    //return returnvalue;
}