#include "expressionslist.hpp"
#include <iostream>

ExpressionsList::ExpressionsList(){

}

ExpressionsList::~ExpressionsList(){
    for(int i = 0; i < elist.size(); i++)
        delete elist[i];
}

void ExpressionsList::add(Type* t){
    elist.push_back(new Expression(t));
}

void ExpressionsList::write(){
    for(int i = 0; i < elist.size(); i++){
        std::cout << elist[i]->getExpression()->getExpression() << std::endl;
    }
}