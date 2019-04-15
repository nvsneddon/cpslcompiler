#include "expressionslist.hpp"
#include "../Statements/write.hpp"
#include <iostream>

ExpressionsList::ExpressionsList(){

}

ExpressionsList::~ExpressionsList(){
    for(int i = 0; i < elist.size(); i++){
		if(dynamic_cast<MemExpression*>(elist[i]) == NULL) {
            delete elist[i];
		}
    }
}

void ExpressionsList::write(){ //Make this one be able to emit all the functions. See if this is needed as well
    for(int i = 0; i < elist.size(); i++){
        elist[i]->write();
    }
}
