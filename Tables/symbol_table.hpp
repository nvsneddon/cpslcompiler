#ifndef SYMBOL_TABLE_HPP
#define SYMBOL_TABLE_HPP 

#include <iostream>
#include <vector>
#include <map>


class SymbolTable{
    public:
        void addVariable(std::map<std::string, int> mymap);
        void printStringLabels();
        int appendString(std::string str);
    private:
        std::vector<std::map<std::string, int>> variables;    
        std::vector<std::map<std::string, std::string>> toPrint;
        std::vector<std::string> stringVariables;
};


#endif