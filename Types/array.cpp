#include "array.hpp"

Array::Array(int l, int h, Type* tprm) : low(l), hi(h){
    //for(int i = l; i <= h; i++){
    //    memory.push_back(new MemExpression(symbols->getOffset(tprm->size()), tprm->getCopyPtr()));
    //}
    arrayType = tprm;
    sizenum = hi-low+1;
    delete tprm;
}

Array::Array(int l, int h) :
    Array(l, h, new Integer()) {}

Array::Array(int l, int h, std::string tstring){
    low = l;
    hi = h;
    sizenum = hi-low+1;
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

RegExpression* Array::getExpressionAt(int arraylocation){
    return NULL;
}

Type* Array::getCopyPtr(){
    return new Array(low, hi, arrayType->getCopyPtr());
}