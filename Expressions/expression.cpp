#include "expression.hpp"
#include <iostream>

Expression::Expression(int expr, std::string theType){
    if (theType.compare("integer") == 0){
        type = new Integer(expr);
    }
    else if (theType.compare("string") == 0){

    }
    else if (theType.compare("character") == 0){
        type = new Character(expr);
    }
    else if (theType.compare("boolean") == 0){
        type = new Bool(expr);
    }
    else{
        std::cerr << "Malaligned Type" << std::endl;
    }
}