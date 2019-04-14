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
    return getExpressionAt(arraylocation, ptr, index, false);
}

MemExpression* Array::getExpressionAt(int arraylocation, std::string ptr, Expression* indexexpr){
    return getExpressionAt(arraylocation, ptr, indexexpr, false);
}

MemExpression* Array::getExpressionAt(int arraylocation, std::string ptr, int index, bool isconstant){
    int address = ((index-low)*arrayType->size() + arraylocation);
    return new MemExpression(address, ptr, arrayType->getCopyPtr(), true, isconstant);
}

MemExpression* Array::getExpressionAt(int arraylocation, std::string ptr, Expression* indexexpr, bool isconstant){
    //int address = ((index-low)*arrayType->size() + arraylocation);
    //return new MemExpression(address, ptr, arrayType->getCopyPtr(), true);
    //indexexpr->write();
    RegExpression* temp = indexexpr->copyAsRegExpression();
    Expression* temp1 = temp->sub(new ConstExpression(low));
    delete temp;
    Expression* temp2 = temp1->mult(new ConstExpression(arrayType->size()));
    delete temp1;
    Expression* temp3 = temp2->add(new ConstExpression(arraylocation));
    delete temp2;
    RegExpression* arraymemlocation = temp3->copyAsRegExpression();
    delete temp3;
    std::cout << "add " << arraymemlocation->getRegister() << ", " << arraymemlocation->getRegister() << ", " << ptr << std::endl;
    return new TempMemExpression(arraymemlocation, arrayType->getCopyPtr(), isconstant);
}

Type* Array::getCopyPtr(){
    return new Array(low, hi, arrayType->getCopyPtr());
}