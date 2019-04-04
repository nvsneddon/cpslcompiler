#include "expression.hpp"

Expression::Expression(int expr, std::string theType){
    if (theType.compare("integer")){
        type = new Integer();
    }
    else if (theType.compare("string")){

    }
    else if (theType.compare("character")){

    }
    else if (theType.compare("boolean")){

    }
}