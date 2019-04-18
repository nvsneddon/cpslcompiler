#ifndef PARAMETERLIST_HPP
#define PARAMETERLIST_HPP

#include <vector>
#include <string>

#include "../Types/type.hpp"

struct Parameter{
    std::string name;
    Type* type;
};

class ParameterList{
public:
    ParameterList();
    void addParameter(std::string n, Type* t);
private:
    std::vector<Parameter> plist;
};

#endif