#ifndef RECORD_HPP
#define RECORD_HPP
#include "type.hpp"
#include <map>
#include <iostream>
#include <vector>

#include "../Expressions/memexpression.hpp"
#include "../Expressions/tempmemexpression.hpp"

class Record : public Type {

public:
    Record();
    Record(std::string);
    void addType(std::string, Type*);
    Type* getTypeInRecord(std::string);
    Type* getCopyPtr();
    std::string getTypeAsString() { return "record"; }
    MemExpression* getExpression(std::string, int);
    int size();
private:
    std::string refPointer;
    std::map<std::string, Type*> types;
    std::map<std::string, int> indexnumber;
};

#endif