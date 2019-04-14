#include "symbol_table.hpp"

SymbolTable::SymbolTable(){
    addScope(); 
}

SymbolTable::~SymbolTable(){
    for(int i = 0; i < variables.size(); i++){
        for (auto it = variables[i].begin(); it != variables[i].end(); it++ ){
            delete it->second;
        }
    }
}

std::string SymbolTable::getReferencePointer(){
    return "$gp";
}

void SymbolTable::declareVariable(std::string varname, Type* t){
    auto it = constants.find(varname);
    if(it != constants.end() && findVariable(varname) != NULL){
        std::cerr << "Cannot declare a variable again\n";
        throw "error";
    }
    variables[0].insert(std::make_pair(varname, new MemExpression(getOffset(t->size()), getReferencePointer(), t)));
}

void SymbolTable::declareConstant(std::string varname, Type* t){
    constants.insert(std::make_pair(varname, new MemExpression(getOffset(t->size()), getReferencePointer(), t)));
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

MemExpression* SymbolTable::findConstant(std::string myvar){
    auto constit = constants.find(myvar);
    if (constit != constants.end()){
        return constit->second;
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
    static int offset = 0;
    int returnvalue = offset;
    offset += size;
    return returnvalue;
}