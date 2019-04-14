#ifndef RECORD_HPP
#define RECORD_HPP
#include "type.hpp"
#include <map>
#include <iostream>

class Record : public Type {

public:
    Record();
    void addType(std::string, Type*);
    Type* getType(std::string);
    int size();
private:
    std::map<std::string, Type*> types;
};

#endif