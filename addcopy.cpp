Expression* Calculation::add(Expression* a, Expression* b){
    if(dynamic_cast<Integer*>(a->getExpressionType()) == NULL && dynamic_cast<Integer*>(b->getExpressionType()) == NULL) {
        throw "Wrong expression type";
    }   
    if(ConstExpression* ca = dynamic_cast<ConstExpression*>(a)){
        if(ConstExpression* cb = dynamic_cast<ConstExpression*>(b)){
            return new ConstExpression(ca->getElement() + cb->getElement());
        }
        else if(RegExpression* rb = dynamic_cast<RegExpression*>(b)){
            RegExpression* newreg = new RegExpression();
            std::cout << "addi " << newreg->getRegister() << ", " << rb->getRegister() << ", " << ca->getElement() << std::endl;;
            return newreg;
        }
    }
    else if(RegExpression* ra = dynamic_cast<RegExpression*>(a)){
        RegExpression* newreg = new RegExpression();
        if(ConstExpression* cb = dynamic_cast<ConstExpression*>(b)){
            std::cout << "addi " << newreg->getRegister() << ", " << ra->getRegister() << ", " << cb->getElement() << std::endl;;
            return newreg;
        }
        else if(RegExpression* rb = dynamic_cast<RegExpression*>(b)){
            std::cout << "add " << newreg->getRegister() << ", " << ra->getRegister() << ", " << rb->getRegister() << std::endl;
            return newreg;
        }
    }
    throw "Compiler Error!";
}
