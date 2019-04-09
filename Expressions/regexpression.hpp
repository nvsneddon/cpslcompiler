class RegExpression : public Expression{
public:
    RegExpression();
    RegExpression(ConstExpression c);
    Expression* add(Expression* other);
private:
    std::string reg;
};

