#include "expressionslist.hpp"
#include "../Statements/write.hpp"
#include <iostream>

ExpressionsList::ExpressionsList(){

}

ExpressionsList::~ExpressionsList(){
    for(int i = 0; i < elist.size(); i++)
        delete elist[i];
}

void ExpressionsList::write(){
    for(int i = 0; i < elist.size(); i++){
        //if(Integer* integ = dynamic_cast<Integer*>(elist[i]->getExpression())) {
        //    // old was safely casted to NewType
        //    Write::write(std::to_string(elist[i]->getExpression()->getExpression()));
        //}
        //else if(Character* chr = dynamic_cast<Character*>(elist[i]->getExpression())) {
        //    // old was safely casted to NewType
        //    std::string s;
        //    s += char(elist[i]->getExpression()->getExpression());
        //    Write::write(s);
        //}
        //else if(CharacterString* str = dynamic_cast<CharacterString*>(elist[i]->getExpression())){
        //    
        //}
    }
}