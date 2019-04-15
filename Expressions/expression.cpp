#include "expression.hpp"

void Expression::ord(){
    if(expressionType->getTypeAsString() == "char"){
        Type* t = expressionType;
        expressionType = new Integer();
        delete t;
    }
    else{
        std::cerr << "Attemted to change " << expressionType->getTypeAsString() << " to a char" << std::endl;
    }
}

void Expression::chr(){
    if(expressionType->getTypeAsString() == "integer"){
        Type* t = expressionType;
        expressionType = new Char();
        delete t;
    }
    else{
        std::cerr << "Attemted to change " << expressionType->getTypeAsString() << " to an integer" << std::endl;
    }
}