#ifndef PROCEDURE_HPP
#define PROCEDURE_HPP

#include <map>
#include <iostream>

#include "../Types/type.hpp"

class Procedure {

public:
    void declare();
    void call();
    std::map<std::string, Type*> params;
};

#endif