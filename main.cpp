#include "includes.hpp"
extern int yyparse();

SymbolTable* symbols;
ExpressionsList* elist;
StatementList* slist;
RegTable* rtable;


int main(){
	symbols = new SymbolTable();
	elist = new ExpressionsList();
	slist = new StatementList();
	rtable = new RegTable();
	yyparse();
	delete symbols;
	delete elist;
	delete slist;
	delete rtable;
}
