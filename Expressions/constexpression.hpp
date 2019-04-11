#ifndef cONSTEXPRESSION_HPP 
#define cONSTEXPRESSION_HPP 
#include "expression.hpp"
#include "regexpression.hpp"
#include "../Types/type.hpp"
#include "../Types/simpletype.hpp"
#include "../Tables/reg_table.hpp"
#include "../Statements/write.hpp"

class ConstExpression : public Expression{
public:
    ConstExpression(int e);
    ConstExpression(int e, Type* t); 
    ConstExpression(int e, std::string t);

    Expression* add(Expression* other);
    Expression* sub(Expression* other);
    Expression* mult(Expression* other);
    Expression* div(Expression* other);
    Expression* mod(Expression* other);
    Expression* lt(Expression* other);
    Expression* lte(Expression* other);
    Expression* gt(Expression* other);
    Expression* gte(Expression* other);    
    Expression* ne(Expression* other);
    Expression* eq(Expression* other);
    Expression* andfun(Expression* other);
    Expression* orfun(Expression* other);

    RegExpression* copyAsRegExpression();

    void write();

    int getElement() { return element; }
    ~ConstExpression();
private:
    int element;
};

#endif
