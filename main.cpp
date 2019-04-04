#include "includes.hpp"
extern int yyparse();

SymbolTable* symbols;
ExpressionsList* elist;


int main(){
	symbols = new SymbolTable();
	elist = new ExpressionsList();
	yyparse();
	delete symbols;
	delete elist;
}
