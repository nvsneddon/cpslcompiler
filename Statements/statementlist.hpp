#ifndef STATEMENTLIST_HPP
#define STATEMENTLIST_HPP 

#include <vector>
#include "statement.hpp"

class StatementList{ 
public:
    void emit(){ for(auto i : sList) i->write(); }
    void add(Statement* stmt){ sList.push_back(stmt); };
    ~StatementList(){ for(auto i : sList) delete i;};
private: 
    std::vector<Statement*> sList;
};

#endif