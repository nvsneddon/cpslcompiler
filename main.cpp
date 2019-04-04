#include "includes.hpp"
extern int yyparse();

SymbolTable* symbols;
ExpressionsList* elist;
StatementList* slist;


int main(){
	symbols = new SymbolTable();
	elist = new ExpressionsList();
	slist = new StatementList();
	yyparse();
	delete symbols;
	delete elist;
	delete slist;
}
