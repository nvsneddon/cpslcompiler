#include "includes.hpp"
extern int yyparse();

SymbolTable* symbols;
ExpressionsList* elist;
StatementList* slist;
RegTable* rtable;
IdList* idlist;
StringList* strlist;


int main(){
	symbols = new SymbolTable();
	elist = new ExpressionsList();
	slist = new StatementList();
	rtable = new RegTable();
	strlist = new StringList();
	yyparse();
	delete symbols;
	delete elist;
	delete slist;
	delete rtable;
	delete strlist;
}
