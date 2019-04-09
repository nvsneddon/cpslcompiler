#include "expressionslist.hpp"
#include "../Statements/write.hpp"
#include <iostream>

ExpressionsList::ExpressionsList(){

}

ExpressionsList::~ExpressionsList(){
    for(int i = 0; i < elist.size(); i++)
        delete elist[i];
}

void ExpressionsList::write(){ //Make this one be able to emit all the functions. See if this is needed as well
    for(int i = 0; i < elist.size(); i++){
        if(Integer* integ = dynamic_cast<Integer*>(elist[i]->getExpressionType())) {
            // old was safely casted to NewType
            if(ConstExpression* con = dynamic_cast<ConstExpression*>(elist[i])) {
                Write::write(std::to_string(con->getElement()));
            }
        }
        else if(Character* chr = dynamic_cast<Character*>(elist[i]->getExpressionType())) {
            // old was safely casted to NewType
            if(ConstExpression* con = dynamic_cast<ConstExpression*>(elist[i])) {
                std::string s;
                s += char(con->getElement());
                Write::write(s);
            }
        }
    }
}