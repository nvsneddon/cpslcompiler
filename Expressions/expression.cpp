#include "expression.hpp"
#include <iostream>

Expression::Expression(int expr, std::string theType){
    if (theType.compare("integer")){
        type = new Integer();
        e = expr;
    }
    else if (theType.compare("string")){

    }
    else if (theType.compare("character")){
        type = new Character();
        e = expr;
    }
    else if (theType.compare("boolean")){
        type = new Boolean();
        e = expr;
    }
    else{
        std::cerr << "Malaligned Type" << std::endl;
    }
}