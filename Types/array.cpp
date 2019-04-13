#include "array.hpp"

Array::Array(int l, int h, Type* tprm) : low(l), hi(h){
    for(int i = l; i <= h; i++){
        memory.push_back(new MemExpression(symbols->getOffset(tprm->size()), tprm->getCopyPtr()));
    }
    sizenum = hi-low+1;
    delete tprm;
}

Array::Array(int l, int h) :
    Array(l, h, new Integer()) {}

Array::Array(int l, int h, std::string tstring){
    low = l;
    hi = h;
    sizenum = hi-low+1;
    for(int i = l; i <= h; i++){
        if(tstring == "integer"){
            memory.push_back(new MemExpression(symbols->getOffset(4), new Integer())); 
        }
        else if(tstring == "char"){
            memory.push_back(new MemExpression(symbols->getOffset(4), new Char())); 
        }
        else if(tstring == "boolean"){
            memory.push_back(new MemExpression(symbols->getOffset(4), new Boolean())); 
        }
    }
}

MemExpression* Array::getExpressionAt(int arraylocation){
    return memory[arraylocation-low];
}

Type* Array::getCopyPtr(){
    return new Array(low, hi, );
}