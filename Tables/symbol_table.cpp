#include "symbol_table.hpp"

void SymbolTable::addVariable(std::map<std::string, int> mymap){
    
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

