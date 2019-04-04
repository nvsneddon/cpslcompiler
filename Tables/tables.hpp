#ifndef TABLES_HPP
#define TABLES_HPP
#include "symbol_table.hpp"
#include "../includes.hpp"

class Tables{
    public:
        //static SymbolTable* getSymboleTable(){ return symbols; }
        //static void setSymbolTable(SymbolTable* address){ symbols = address; }
        Tables(){ test = new int(); }
        ~Tables(){ delete test; }
    private:
        //static SymbolTable* symbols;
        int* test;
};

#endif