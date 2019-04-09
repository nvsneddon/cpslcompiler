#ifndef REG_TABLE_HPP
#define REG_TABLE_HPP

#include <stack>
#include <string>

class RegTable{
public:
    RegTable();
    std::string getRegister();
    void addRegister(std::string r);
private:
    std::stack<std::string> regs;
};

#endif