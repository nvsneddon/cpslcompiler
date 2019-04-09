#include "regexpression.hpp"

//RegExpression::RegExpression(ConstExpression* c){
//    reg = rtable->getRegister();
//    std::cout << "li " << reg << ", " << c->getElement() << std::endl;
//}

RegExpression::RegExpression(){
    reg = "$t0";
}


Expression* RegExpression::add(Expression* other){
    return new RegExpression();
}
Expression* RegExpression::sub(Expression* other) {
    return new RegExpression();
}
Expression* RegExpression::mult(Expression* other) {
    return new RegExpression();
}
Expression* RegExpression::div(Expression* other) {
    return new RegExpression();
}
Expression* RegExpression::mod(Expression* other) {
    return new RegExpression();
}
Expression* RegExpression::lt(Expression* other) {
    return new RegExpression();
}
Expression* RegExpression::lte(Expression* other) {
    return new RegExpression();
}
Expression* RegExpression::gt(Expression* other) {
    return new RegExpression();
}
Expression* RegExpression::gte(Expression* other) {
    return new RegExpression();
}
Expression* RegExpression::ne(Expression* other) {
    return new RegExpression();
}
Expression* RegExpression::eq(Expression* other) {
    return new RegExpression();
}
Expression* RegExpression::andfun(Expression* other) {
    return new RegExpression();
}
Expression* RegExpression::orfun(Expression* other) {
    return new RegExpression();
}