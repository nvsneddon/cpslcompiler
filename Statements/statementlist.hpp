#ifndef STATEMENTLIST_HPP
#define STATEMENTLIST_HPP 

#include <vector>
#include "statement.hpp"

class StatementList{ 
public:
    void emit(){
        for(auto i:sList) i->write();
    }
private: 
    std::vector<Statement*> sList;
};

#endif