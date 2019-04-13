#include "array.hpp"

Array::Array(int l, int h, Type* tprm) : low(l), hi(h){
    //for(int i = l; i <= h; i++){
    //    memory.push_back(new MemExpression(symbols->getOffset(tprm->size()), tprm->getCopyPtr()));
    //}
    arrayType = tprm;
    numofelements = hi-low+1;
}

Array::Array(int l, int h) :
    Array(l, h, new Integer()) {}

Array::Array(int l, int h, std::string tstring){
    low = l;
    hi = h;
    numofelements = hi-low+1;
    if(tstring == "integer"){
        arrayType = new Integer();
    }
    else if(tstring == "char"){
        arrayType = new Char();
    }
    else if(tstring == "boolean"){
        arrayType = new Boolean();
    }
}

MemExpression* Array::getExpressionAt(int arraylocation, std::string ptr, int index){
    int address = ((index-low)*arrayType->size() + arraylocation);
    return new MemExpression(address, ptr, arrayType->getCopyPtr(), true);
}

Type* Array::getCopyPtr(){
    return new Array(low, hi, arrayType->getCopyPtr());
}