#include "includes.hpp"
extern int yyparse();

SymbolTable* symbols;
ExpressionsList* elist;
StatementList* slist;
RegTable* rtable;
IdList* idlist;
StringList* strlist;
LoopLabels* llbl;
FunctionList* flist;


int main(){
	symbols = new SymbolTable();
	elist = new ExpressionsList();
	slist = new StatementList();
	rtable = new RegTable();
	strlist = new StringList();
	llbl = new LoopLabels();
	flist = new FunctionList();
	std::cout << "j main" << std::endl;
	yyparse();
	delete symbols;
	delete elist;
	delete slist;
	delete rtable;
	delete strlist;
	delete llbl;
	delete flist;
}
