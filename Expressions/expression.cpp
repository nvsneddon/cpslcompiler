#include "expression.hpp"
#include <iostream>

ConstExpression::ConstExpression(int e){
    expressionType = new SimpleType();
}

ConstExpression::ConstExpression(int e, Type* t){

}

ConstExpression::~ConstExpression(){
    delete expressionType;
}
