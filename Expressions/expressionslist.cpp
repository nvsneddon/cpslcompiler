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
        elist[i]->write();
        //if(Integer* integ = dynamic_cast<Integer*>(elist[i]->getExpressionType())) {
        //    // old was safely casted to NewType
        //    if(ConstExpression* con = dynamic_cast<ConstExpression*>(elist[i])) {
        //        Write::write(std::to_string(con->getElement()));
        //    }
        //}
        //else if(Char* chr = dynamic_cast<Char*>(elist[i]->getExpressionType())) {
        //    // old was safely casted to NewType
        //    if(ConstExpression* con = dynamic_cast<ConstExpression*>(elist[i])) {
        //        std::string s;
        //        s += char(con->getElement());
        //        Write::write(s);
        //    }
        //}
        //else if(Boolean* bl = dynamic_cast<Boolean*>(elist[i]->getExpressionType())){
        //    if(ConstExpression* con = dynamic_cast<ConstExpression*>(elist[i])){
        //        Write::write(con->getElement() == 1 ? "True" : "False");
        //    }
        //}
    }
}