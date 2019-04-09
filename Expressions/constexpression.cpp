#include "constexpression.hpp"
#include <iostream>
#include <typeinfo>

ConstExpression::ConstExpression(int e){
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
    if(ConstExpression* con = dynamic_cast<ConstExpression*>(other)){
        if(dynamic_cast<Integer*>(expressionType) == NULL && dynamic_cast<Integer*>(other->getExpressionType()) == NULL) {
            throw "Wrong expression type";
        }   
        return new ConstExpression(element + con->getElement());
    }
    return new ConstExpression(15);
}


//Subtraction functions
Expression* ConstExpression::sub(Expression* other){
    if(ConstExpression* con = dynamic_cast<ConstExpression*>(other)){
        if(dynamic_cast<Integer*>(expressionType) == NULL && dynamic_cast<Integer*>(other->getExpressionType()) == NULL) {
            throw "Wrong expression type";
        }   
        return new ConstExpression(element - con->getElement());
    }
    return new ConstExpression(15);
}


//Multiplication functions
Expression* ConstExpression::mult(Expression* other){
    if(ConstExpression* con = dynamic_cast<ConstExpression*>(other)){
        if(dynamic_cast<Integer*>(expressionType) == NULL && dynamic_cast<Integer*>(other->getExpressionType()) == NULL) {
            throw "Wrong expression type";
        }   
        return new ConstExpression(element * con->getElement());
    }
    return new ConstExpression(15);
}



//Division functions
Expression* ConstExpression::div(Expression* other){
    if(ConstExpression* con = dynamic_cast<ConstExpression*>(other)){
        if(dynamic_cast<Integer*>(expressionType) == NULL && dynamic_cast<Integer*>(other->getExpressionType()) == NULL) {
            throw "Wrong expression type";
        }   
        return new ConstExpression(element / con->getElement());
    }
    return new ConstExpression(15);
}


//Mod functions
Expression* ConstExpression::mod(Expression* other){
    if(ConstExpression* con = dynamic_cast<ConstExpression*>(other)){
        if(dynamic_cast<Integer*>(expressionType) == NULL && dynamic_cast<Integer*>(other->getExpressionType()) == NULL) {
            throw "Wrong expression type";
        }   
        return new ConstExpression(element % con->getElement());
    }
    return new ConstExpression(15);
}


Expression* ConstExpression::lt(Expression* other){
    bool result;
    if(ConstExpression* con = dynamic_cast<ConstExpression*>(other)){
        result = element < con->getElement();
    }
    return new ConstExpression(result ? 1 : 0, new Boolean());
}


Expression* ConstExpression::lte(Expression* other){
    bool result;
    if(ConstExpression* con = dynamic_cast<ConstExpression*>(other)){
        result = element <= con->getElement();
    }
    return new ConstExpression(result ? 1 : 0, new Boolean());
}

Expression* ConstExpression::gt(Expression* other){
    bool result;
    if(ConstExpression* con = dynamic_cast<ConstExpression*>(other)){
        result = element > con->getElement();
    }
    return new ConstExpression(result ? 1 : 0, new Boolean());
}

Expression* ConstExpression::gte(Expression* other){
    bool result;
    if(ConstExpression* con = dynamic_cast<ConstExpression*>(other)){
        result = element >= con->getElement();
    }
    return new ConstExpression(result ? 1 : 0, new Boolean());
}

Expression* ConstExpression::ne(Expression* other){
    bool result;
    if(ConstExpression* con = dynamic_cast<ConstExpression*>(other)){
        result = element != con->getElement();
    }
    return new ConstExpression(result ? 1 : 0, new Boolean());
}

Expression* ConstExpression::eq(Expression* other){
    bool result;
    if(ConstExpression* con = dynamic_cast<ConstExpression*>(other)){
        result = element == con->getElement();
    }
    return new ConstExpression(result ? 1 : 0, new Boolean());
}

Expression* ConstExpression::andfun(Expression* other){
    bool result;
    if(ConstExpression* con = dynamic_cast<ConstExpression*>(other)){
        result = element && con->getElement();
    }
    return new ConstExpression(result ? 1 : 0, new Boolean());
}

Expression* ConstExpression::orfun(Expression* other){
    bool result;
    if(ConstExpression* con = dynamic_cast<ConstExpression*>(other)){
        result = element || con->getElement();
    }
    return new ConstExpression(result ? 1 : 0, new Boolean());
}