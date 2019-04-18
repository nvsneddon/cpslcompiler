#include "reg_table.hpp"

RegTable::RegTable(){
    regs.push("$s7");
    regs.push("$s6");
    regs.push("$s5");
    regs.push("$s4");
    regs.push("$s3");
    regs.push("$s2");
    regs.push("$s1");
    regs.push("$s0");

    regs.push("$t9");
    regs.push("$t8");
    regs.push("$t7");
    regs.push("$t6");
    regs.push("$t5");
    regs.push("$t4");
    regs.push("$t3");
    regs.push("$t2");
    regs.push("$t1");
    regs.push("$t0");
    usedregs.push_back("$ra");
}

std::string RegTable::getNewRegister(){
    if(regs.empty()){
        std::cerr << "Out of registers" << std::endl;
        throw "error";
    }
    std::string returnstring = regs.top();
    regs.pop();
    usedregs.push_back(returnstring);
    return returnstring;
}
void RegTable::addRegister(std::string r){
    regs.push(r);
    auto it = std::find(usedregs.begin(), usedregs.end(), r);
    if (it != usedregs.end()){
        usedregs.erase(it);
    } else{
        std::cerr << "Something went wrong here\n";
    }
}

void RegTable::getStats(){
    std::cerr << "Size is " << regs.size() << std::endl;
    //while(!regs.empty()){
    //    std::cerr << regs.top() << std::endl;
    //    regs.pop();
    //}
}