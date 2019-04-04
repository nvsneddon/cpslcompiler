#ifndef EXPRESSION_HPP 
#define EXPRESSION_HPP

#include <string>
#include "../Types/type.hpp"

class Expression{
    public:
        Expression(int expr, std::string theType);
        void test() {}
    private:
        Type* type;
};

#endif