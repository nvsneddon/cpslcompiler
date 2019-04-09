#include "expression.hpp"
#include <iostream>

ConstExpression::ConstExpression(int e){
    std::cerr << "const\n";
    expressionType = new Integer();
    element = e;
}

ConstExpression::ConstExpression(int e, Type* t){
    expressionType = t;
    element = e;
}

ConstExpression::~ConstExpression(){
    delete expressionType;
}

    
//Add functions
Expression* ConstExpression::add(Expression* other){
    std::cerr << "djifhauewhfu\n";
    return new ConstExpression(25);
}
    
Expression* ConstExpression::add(ConstExpression* other){
    if(dynamic_cast<Integer*>(expressionType) == NULL && dynamic_cast<Integer*>(other->getExpressionType()) == NULL) {
        throw "Wrong expression type";
    }   
    std::cerr << "Did we make it here?\n";
    return new ConstExpression(element + other->getElement());
}

Expression* RegExpression::add(Expression* other){
    return new ConstExpression(25);
}
    
Expression* MemExpression::add(Expression* other){
    return new ConstExpression(25);
}



//Subtraction functions
Expression* ConstExpression::sub(Expression* other){
    return new ConstExpression(25);
}
    
Expression* ConstExpression::sub(ConstExpression* other){
    if(dynamic_cast<Integer*>(expressionType) == NULL && dynamic_cast<Integer*>(other->getExpressionType()) == NULL) {
        throw "Wrong expression type";
    }   
    return new ConstExpression(element - other->getElement());
}



//Multiplication functions
Expression* ConstExpression::mult(Expression* other){
    return new ConstExpression(25);
}
    
Expression* ConstExpression::mult(ConstExpression* other){
    if(dynamic_cast<Integer*>(expressionType) == NULL && dynamic_cast<Integer*>(other->getExpressionType()) == NULL) {
        throw "Wrong expression type";
    }   
    return new ConstExpression(element * other->getElement());
}


//Division functions
Expression* ConstExpression::div(Expression* other){
    return new ConstExpression(25);
}
    
Expression* ConstExpression::div(ConstExpression* other){
    if(dynamic_cast<Integer*>(expressionType) == NULL && dynamic_cast<Integer*>(other->getExpressionType()) == NULL) {
        throw "Wrong expression type";
    }   
    return new ConstExpression(element / other->getElement());
}



//Mod functions
Expression* ConstExpression::mod(Expression* other){
    return new ConstExpression(25);
}
    
Expression* ConstExpression::mod(ConstExpression* other){
    if(dynamic_cast<Integer*>(expressionType) == NULL && dynamic_cast<Integer*>(other->getExpressionType()) == NULL) {
        throw "Wrong expression type";
    }   
    return new ConstExpression(element % other->getElement());
}