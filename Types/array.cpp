#include "array.hpp"

Array::Array(int l, int h, Type* tprm){
    low = l;
    hi = h;
    t = tprm;
}

Array::Array(int l, int h){
    low = l;
    hi = h;
    t = new Integer();
}

Array::Array(int l, int h, std::string tstring){
    low = l;
    hi = h;
    if(tstring == "integer"){
        t = new Integer();
    }
    else if(tstring == "char"){
        t = new Char();
    }
    else if(tstring == "string"){
        t = new String();
    }
    else if(tstring == "boolean"){
        t = new Boolean();
    }
}

Type* Array::getCopyPtr(){
    return new Array(low, hi);
}