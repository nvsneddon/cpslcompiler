#ifndef SYMBOL_TABLE_HPP
#define SYMBOL_TABLE_HPP 

#include <iostream>
#include <vector>
#include <map>

class SymbolTable{
    public:
        void add();
    private:
        std::vector<std::map<std::string, int>> variables;    
        std::vector<std::map<std::string, std::string>> toPrint;
};


#endif