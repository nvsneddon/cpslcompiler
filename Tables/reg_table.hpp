#ifndef REG_TABLE_HPP
#define REG_TABLE_HPP

#include <stack>
#include <string>
#include <iostream>

class RegTable{
public:
    RegTable();
    std::string getNewRegister();
    void addRegister(std::string r);
    int getSize(){ return regs.size(); }
    void getStats();
private:
    std::stack<std::string> regs;
};

#endif