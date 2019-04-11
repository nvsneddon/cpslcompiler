#include "emptyexpression.hpp"

EmptyExpression::EmptyExpression(){
    expressionType = new Integer();
}

EmptyExpression::EmptyExpression(Type* t){
    expressionType = t;
}