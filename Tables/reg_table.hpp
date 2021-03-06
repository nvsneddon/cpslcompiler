#ifndef REG_TABLE_HPP
#define REG_TABLE_HPP

#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

class RegTable{
public:
    RegTable();
    std::string getNewRegister();
    void addRegister(std::string r);
    int getSize(){ return regs.size(); }
    int getUsedSize() { return usedregs.size(); }
    int getSpillRegSize();
    void getStats();
    void spillregisters(int offset);
    void unspillregisters(int offset);
private:
    std::stack<std::string> regs;
    std::vector<std::string> usedregs;
    std::vector<std::string> spilledregs;
};

#endif