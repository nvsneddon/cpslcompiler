#include "array.hpp"

Array::Array(int l, int h, Type* tprm) : low(l), hi(h){
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

MemExpression* Array::getExpressionAt(int arraylocation, std::string ptr, Expression* indexexpr){
    //int address = ((index-low)*arrayType->size() + arraylocation);
    //return new MemExpression(address, ptr, arrayType->getCopyPtr(), true);
    RegExpression* temp = indexexpr->copyAsRegExpression();
    Expression* temp1 = temp->sub(new ConstExpression(arraylocation));
    delete temp;
    Expression* temp2 = temp1->mult(new ConstExpression(arrayType->size()));
    delete temp1;
    Expression* temp3 = temp2->add(new ConstExpression(arraylocation));
    delete temp2;
    RegExpression* arraymemlocation = temp3->copyAsRegExpression();
    return new TempMemExpression(arraymemlocation);
}

Type* Array::getCopyPtr(){
    return new Array(low, hi, arrayType->getCopyPtr());
}