%{
	#include <iostream>
	#include <cstring>
	#include <vector>

	extern "C" int yylineno;

	extern int yylex();
	void yyerror(const char*);
%}

%code requires{
	#ifndef INCLUDES_HPP
	#define INCLUDES_HPP
	#include "includes.hpp"

	extern SymbolTable* symbols;
	extern StatementList* slist;
	extern RegTable* rtable;
	extern LoopLabels* llbl;
	extern StringList* strlist;

	#endif
}

%union
{
	int num;
	float val;
	char* id;
	Type* tpe;
	IdList* ids;
	SimpleType* stpe;
	Array* atpe;
	Record* rcrd;
	Expression* express;
	ExpressionsList* elist;
}

%token ADD
%token SUB
%token MULT
%token DIV
%token AND
%token OR
%token TILDA
%token EQ
%token ASSIGN
%token ARROWS
%token LT 
%token GT
%token GTE
%token LTE
%token DEC
%token COMMA 
%token COL
%token SEMCOL
%token POPEN
%token PCLOSE
%token BOPEN
%token BCLOSE
%token PERC 

%token ARRAY
%token START
%token CHR
%token CONST
%token DO
%token DOWNTO
%token ELSE
%token ELSEIF
%token END
%token FOR
%token FORWARD
%token FUNCTION
%token IF
%token OF
%token ORD
%token PRED
%token PROCEDURE
%token READ
%token RECORD
%token REF
%token REPEAT
%token RETURN
%token STOP
%token SUCC
%token THEN
%token TO
%token TYPE
%token UNTIL
%token VAR
%token WHILE
%token WRITE
%token ID
%token NUMBER
%token CHAR
%token STR

%type<id> ID
%type<val> NUMBER
%type<ids> IDList
%type<express> LValue
%type<rcrd> recordsubtype
%type<rcrd> recordtype
%type<tpe> simpletype 
%type<atpe> arraytype
%type<tpe> Typestatement
%type<id> CHAR
%type<id> STR
%type<num> whilebegin
%type<num> whilelabel
%type<num> ifbegin
%type<num> iflabel
%type<num> elseifbegin
%type<num> elseiflabel
%type<num> repeatlabel
%type<num> ForExpr 
%type<num> RepeatStatement
%type<express> Expression
%type<elist> ExpressionsList


%left OR
%left AND
%left ADD SUB
%left MULT DIV PERC
%nonassoc EQ ARROWS GT GTE LT LTE
%right TILDA
%right NEG

%define parse.error verbose
%locations
%%

Program: ConstantOption TypeOption VarOption Profunct Block DEC {
	std::cout << "li $v0, 10" << std::endl;
	std::cout << "syscall" << std::endl;
	strlist->printLabels();
};

ConstantOption: ConstantDecl {}
	| {};

TypeOption: TypeDecl {}
	| {};

VarOption: VarDecl {}
	| {};

Profunct: Profunct ProcedureDecl {} 
| Profunct FunctionDecl {} 
| ProcedureDecl {}
| FunctionDecl {}
| {};

ConstantDecl: CONST ConstSubDecl {} ;

ConstSubDecl: ConstSubDecl ID EQ Expression SEMCOL {
	ConstExpression* c = dynamic_cast<ConstExpression*>($4);
	if(c == NULL){
		std::cerr << "Constant not a constant value\n";
		throw "Fit";
	}
	symbols->declareConstant($2, c);	
} 
| ID EQ Expression SEMCOL {
	ConstExpression* c = dynamic_cast<ConstExpression*>($3);
	if(c == NULL){
		std::cerr << "Constant not a constant value\n";
		throw "Fit";
	}
	symbols->declareConstant($1, c);	
}; 

TypeDecl: TYPE SubTypeDecl {};

SubTypeDecl: SubTypeDecl ID EQ Typestatement SEMCOL {
	symbols->declareType(std::string($2), $4->getCopyPtr());
	//symbols->declareType(std::string($2), $4);
	//delete $4;
} 
| ID EQ Typestatement SEMCOL {
	symbols->declareType(std::string($1), $3->getCopyPtr());
	//delete $3;
};

VarDecl: VAR SubVarDecl {}; 
SubVarDecl: SubVarDecl IDList COL Typestatement SEMCOL {
	for(int i = 0; i < $2->ids.size(); i++){
		symbols->declareVariable($2->ids[i], $4->getCopyPtr());
	}
	//symbols->printStats();
	delete $4;
} 
| IDList COL Typestatement SEMCOL {
	for(int i = 0; i < $1->ids.size(); i++){
		symbols->declareVariable($1->ids[i], $3->getCopyPtr());
	}
	//symbols->printStats();
	delete $3;
}
; 

Typestatement: simpletype {
	$$ = $1;
} 
| recordtype {
	$$ = $1;
} 
| arraytype {
	$$ = $1;
};


simpletype: ID {
	Type* t = symbols->findType(std::string($1));
	if (t != NULL){
		$$ = t;
	}		
	else{
		if(!strcmp($1, "integer") || !strcmp($1, "INTEGER")){
			$$ = new Integer();	
		}
		else if(!strcmp($1, "char") || !strcmp($1, "CHAR")){
			$$ = new Char();	
		}
		else if(!strcmp($1, "string") || !strcmp($1, "STRING")){
			$$ = new String();	
		}
		else if(!strcmp($1, "boolean") || !strcmp($1, "BOOLEAN")){
			$$ = new Boolean();	
		}
	}
}
;
recordtype: RECORD recordsubtype END { $$ = $2; } 
| RECORD END {}
;
recordsubtype: recordsubtype IDList COL Typestatement SEMCOL {
	for(int i = 0; i < $2->ids.size(); i++){
		$$->addType($2->ids[i], $4->getCopyPtr());
	}
	//delete $4;
}
| IDList COL Typestatement SEMCOL {
	$$ = new Record();
	for(int i = 0; i < $1->ids.size(); i++){
		$$->addType($1->ids[i], $3->getCopyPtr());
	}
	//delete $3;
}
;
arraytype: ARRAY BOPEN Expression COL Expression BCLOSE OF Typestatement {
	ConstExpression* lowexpr = dynamic_cast<ConstExpression*>($3);
	ConstExpression* hiexpr = dynamic_cast<ConstExpression*>($5);
	if(hiexpr == NULL or lowexpr == NULL){
		std::cerr << "Array expression doesn't evaluate to a constant. Cannot initialize.\n";
		throw "error";
	}
	if(dynamic_cast<Integer*>(lowexpr->getExpressionType()) == NULL or dynamic_cast<Integer*>(hiexpr->getExpressionType()) == NULL){
		std::cerr << "Expressions of arrays must be integers\n";
		throw "error";
	}
	Array* arraytype = new Array(lowexpr->getElement(), hiexpr->getElement(), $8->getCopyPtr());
	//delete $8;
	$$ = arraytype;
}
;

IDList: IDList COMMA ID {
	//Do I do this or not? With the expressionlist it seems to be working fine.
	$$=$1;
	$$->ids.push_back(std::string($3));
}  
| ID {
	$$ = new IdList();
	$$->ids.push_back(std::string($1));
};

ProcedureDecl: PROCEDURE ID POPEN FormalParameters PCLOSE SEMCOL body SEMCOL {}
| PROCEDURE ID POPEN FormalParameters PCLOSE SEMCOL FORWARD SEMCOL {}
;
FunctionDecl: FUNCTION ID POPEN FormalParameters PCLOSE COL Typestatement SEMCOL body SEMCOL{}
| FUNCTION ID POPEN FormalParameters PCLOSE COL Typestatement SEMCOL FORWARD SEMCOL{}
; 

body: ConstSubDecl TypeDecl VarDecl Block {}
| TypeDecl VarDecl Block {}
| ConstSubDecl VarDecl Block {}
| ConstSubDecl TypeDecl Block {}
| TypeDecl Block {}
| ConstSubDecl Block {}
| VarDecl Block {}
| Block {}
;

Block: START StatementSequence END {}
	;

FormalParameters: {}
| FormalParameters SEMCOL VarRef IDList COL Typestatement {} 
| FormalParameters SEMCOL IDList COL Typestatement {} 
| VarRef IDList COL Typestatement {} 
| IDList COL Typestatement {};
	
VarRef: VAR {} 
| REF {};

StatementSequence: StatementSequence SEMCOL Statement {} 
| Statement {};

Statement: Assignment {} 
| IfStatement {} 
| WhileStatement {} 
| RepeatStatement {} 
| ForStatement {} 
| StopStatement {
	std::cout << "li $v0, 10" << std::endl;
	std::cout << "syscall" << std::endl;
	exit(0);
} 
| ReturnStatement {} 
| ReadStatement {} 
| WriteStatement {} 
| ProcedureCall {} 
| {};

IfStatement: ifbody ElseIfStatement ElseStatement END {
	Write::comment("End of ifstatement with an elseif and else statement");
	std::cout << llbl->getEndLabel() << ":" << std::endl;
	llbl->incEndLabel();
	llbl->incIfLabel();
}
| ifbody ElseStatement END {
	Write::comment("End of ifstatement with an else statement");
	std::cout << llbl->getEndLabel() << ":" << std::endl;
	llbl->incEndLabel();
	llbl->incIfLabel();
}
| ifbody ElseIfStatement END {
	Write::comment("End of ifstatement with an elseif statement");
	std::cout << "eval" << llbl->ifLabel() << ":" << std::endl;
	std::cout << llbl->getEndLabel() << ":" << std::endl;
	llbl->incEndLabel();
	llbl->incIfLabel();
}
| ifbegin THEN StatementSequence END {
	//std::cout << "eval" << $1 << ":" << std::endl;
	std::cout << llbl->getEndLabel() << ":" << std::endl;
	std::cout << "eval" << $1 << ":" << std::endl;
	llbl->incIfLabel();
	llbl->incEndLabel();
	Write::comment("End of ifstatement with no else or else if");
};

ifbody: ifbegin THEN StatementSequence {
	std::cout << "j " << llbl->getEndLabel() << std::endl;
	std::cout << "eval" << $1 << ":\n";
	llbl->incIfLabel();
	Write::comment("Inside ifbody");
};

ifbegin: iflabel Expression {
	if(ConstExpression* c = dynamic_cast<ConstExpression*>($2)){
		if(c->getElement() != 0){

		}
		else{
			std::cout << "j " << $1 << std::endl;
		}
	}
	else{
		RegExpression* r = $2->copyAsRegExpression();
		std::cout << "beqz " << r->getRegister() << ", eval" << $1 << std::endl;
		delete r;
	}
	$$ = $1;
	delete $2;
	Write::comment("If begin");
};

iflabel: IF {
	llbl->incIfLabel();
	$$ = llbl->ifLabel();
	};


ElseIfStatement: ElseIfStatement elseifbegin THEN StatementSequence {
	std::cout << "j " << llbl->getEndLabel() << std::endl;
	std::cout << "eval" << llbl->ifLabel() << ":\n";
	//llbl->incIfLabel();
	//Write::comment("elseif statement with prior elseif statements");
}
| elseifbegin THEN StatementSequence {
	std::cout << "j " << llbl->getEndLabel() << std::endl;
	std::cout << "eval" << llbl->ifLabel() << ":\n";
	//llbl->incIfLabel();
	//Write::comment("elseif statement with no prior elseif statement");
};

elseifbegin: elseiflabel Expression {
	if(ConstExpression* c = dynamic_cast<ConstExpression*>($2)){
		if(c->getElement() != 0){

		}
		else{
			std::cout << "j " << llbl->ifLabel() << std::endl;
		}
	}
	else{
		RegExpression* r = $2->copyAsRegExpression();
		std::cout << "beqz " << r->getRegister() << ", eval" << $1 << std::endl;
		delete r;
	}
	Write::comment("Else if begin");
	$$ = $1;
	delete $2;
};

elseiflabel: ELSEIF {
	//std::cout << "eval" << llbl->ifLabel() << ":" << std::endl; 
	llbl->incIfLabel();
	$$ = llbl->ifLabel();
	//Write::comment("Else if label");
};


ElseStatement: ELSE StatementSequence {};

WhileStatement: whilebegin DO StatementSequence END {
	std::cout << "j while_test" << $1 << std::endl;
	std::cout << "while_end" << $1 << ":" << std::endl; 
};

whilebegin: whilelabel Expression{
	if(ConstExpression* c = dynamic_cast<ConstExpression*>($2)){
		if(c->getElement() != 0){
			//while evaluates to true
		}
		else{
			std::cout << "j while_end" << $1 << std::endl;
		}
	}
	else{
		RegExpression* r = $2->copyAsRegExpression();
		std::cout << "beqz " << r->getRegister() << ", while_end" << $1 << std::endl;
		delete r;
	}
	$$ = $1;
	delete $2;
};

whilelabel: WHILE{
	int x = LoopLabels::whileLabel();
	std::cout << "while_test" << x << ":" << std::endl;
	$$ = x;
};

RepeatStatement: repeatlabel StatementSequence UNTIL Expression {
	if(ConstExpression* c = dynamic_cast<ConstExpression*>($4)){
		if(c->getElement() != 0){
		}
		else{
			std::cout << "j repeat" << $1 << std::endl;
		}
	}
	else{
		RegExpression* r = $4->copyAsRegExpression();
		std::cout << "beqz " << r->getRegister() << ", repeat" << $1 << std::endl;
		delete r;
	}
	$$ = $1;
	delete $4;
};

repeatlabel: REPEAT{
	int x = LoopLabels::whileLabel();
	std::cout << "repeat" << x << ":" << std::endl;
	$$ = x;
};

ForStatement: ForExpr DOWNTO Expression DO StatementSequence END {

	symbols->removeScope();
}
| ForExpr TO Expression DO StatementSequence END {

	symbols->removeScope();
};

ForExpr: FOR ID ASSIGN Expression{
	//This part makes initializes the expression
	int x = LoopLabels::forLabel();
	symbols->addScope();
	symbols->declareVariable(std::string($2), $4->getExpressionType() -> getCopyPtr());
	MemExpression* m = symbols->findVariable(std::string($2));
	m->storeExpression($4);
	if(MemExpression* m2 = dynamic_cast<MemExpression*>($4)){
		if(m2->isTemporary()){
			delete $4;
		}
	}
	delete $4;
	std::cout << "forbody" << x << std::endl;
	$$ = x;
};

StopStatement: STOP {};

ReturnStatement: RETURN Expression {} 
| RETURN {};

ReadStatement: READ POPEN ReadValues PCLOSE {};

ReadValues: ReadValues COMMA LValue {
	MemExpression* mymemory = dynamic_cast<MemExpression*>($3);
	if(mymemory == NULL){
		std::cerr << "Expression not defined in read statement\n";
		throw "Variable not defined error";
	}
	if(mymemory->getExpressionType()->getTypeAsString() == "char"){
		RegExpression* myreg = new RegExpression(new Integer());
		std::cout << "li $v0, 12" << std::endl;
		std::cout << "syscall" << std::endl;
		std::cout << "move " << myreg->getRegister() << " $v0" << std::endl;
		mymemory->storeExpression(myreg);
		delete myreg;
	}
	else if(mymemory->getExpressionType()->getTypeAsString() == "integer"){
		RegExpression* myreg = new RegExpression(new Integer());
		std::cout << "li $v0, 5" << std::endl;
		std::cout << "syscall" << std::endl;
		std::cout << "move " << myreg->getRegister() << " $v0" << std::endl;
		mymemory->storeExpression(myreg);
		delete myreg;
	}
	else{
		std::cerr << "Value not an integer or a char\n";
	}
} 
| LValue { 

	MemExpression* mymemory = dynamic_cast<MemExpression*>($1);
	if(mymemory == NULL){
		std::cerr << "Variable not defined in read statement\n";
		throw "Variable not defined error";
	}
	if(mymemory->getExpressionType()->getTypeAsString() == "char"){
		RegExpression* myreg = new RegExpression(new Integer());
		std::cout << "li $v0, 12" << std::endl;
		std::cout << "syscall" << std::endl;
		std::cout << "move " << myreg->getRegister() << " $v0" << std::endl;
		mymemory->storeExpression(myreg);
		delete myreg;
	}
	else if(mymemory->getExpressionType()->getTypeAsString() == "integer"){
		RegExpression* myreg = new RegExpression(new Integer());
		std::cout << "li $v0, 5" << std::endl;
		std::cout << "syscall" << std::endl;
		std::cout << "move " << myreg->getRegister() << " $v0" << std::endl;
		mymemory->storeExpression(myreg);
		delete myreg;
	}
	else{
		std::cerr << "Value not an integer or a char\n";
	}
};

WriteStatement: WRITE POPEN ExpressionsList PCLOSE {
	$3->write();
	delete $3;
};

ProcedureCall: ID POPEN ExpressionsList PCLOSE {
}
| ID POPEN PCLOSE {};

ExpressionsList: ExpressionsList COMMA Expression { 
	$1->add($3); 
	$$ = $1;
} 
| Expression {
	$$ = new ExpressionsList();
	$$->add($1);
};

Assignment: LValue ASSIGN Expression {
	MemExpression* mymemory = dynamic_cast<MemExpression*>($1);
	if(mymemory == NULL){
		std::cerr << "Bad l value\n";
		throw "Variable not defined error";
	}
	if(mymemory->getExpressionType()->getTypeAsString() != $3->getExpressionType()->getTypeAsString()){
		std::cerr << "Mismatching types\n";
		std::cerr << mymemory->getExpressionType()->getTypeAsString() << std::endl;
		std::cerr << $3->getExpressionType()->getTypeAsString() << std::endl;
		throw "False type error";
	}
	mymemory->storeExpression($3);	
	MemExpression* m = dynamic_cast<MemExpression*>($3); 

	if(m == NULL) {
		delete $3;
	}
	else if(m->isTemporary()){
		delete $3;
	}

	if(dynamic_cast<TempMemExpression*>($1) != NULL){
		delete $1;
	}
};
LValue: ID {
	//$$ = $1;
	Write::comment("Looking for " + std::string($1));
	Expression* c = symbols->findConstant(std::string($1));
	if (c != NULL){
		$$ = c;
	}
	else{
		MemExpression* expr = symbols->findVariable(std::string($1));
		if (expr != NULL){
			$$ = expr;
		}
		else if(!strcmp($1, "true") || !strcmp($1, "TRUE")){
			$$ = new ConstExpression(1, new Boolean());
		}
		else if(!strcmp($1, "false") || !strcmp($1, "FALSE")){
			$$ = new ConstExpression(0, new Boolean());
		}
		else{
			std::cerr << "Variable " << $1 << " not defined" << std::endl;
			throw "L Value error";
		}
	}
} //Thiis one is for normal variables
| LValue DEC ID {
	if(MemExpression* mlv = dynamic_cast<MemExpression*>($1)){
		Record* r = dynamic_cast<Record*>(mlv->getExpressionType());
		if (r == NULL){
			std::cerr << "Record not found!" << std::endl;
			throw "error";
		}
		$$ = r->getExpression(std::string($3), mlv->getOffset());
	} else {
		std::cerr << "This didn't go well for the record\n";
		throw "error";
	}
} //This one is for records
| LValue BOPEN Expression BCLOSE {
	if(ConstExpression* cexpression = dynamic_cast<ConstExpression*>($1)){
		std::cerr << "Cannot get array from boolean value" << std::endl;
		std::cerr << cexpression->getElement() << cexpression->getExpressionType()->getTypeAsString() << std::endl;

		throw "fit";
	}
	MemExpression* arraymem = dynamic_cast<MemExpression*>($1);
	ConstExpression* cexpr = dynamic_cast<ConstExpression*>($3);
	if($3->getExpressionType()->getTypeAsString() != "integer"){
		std::cerr << "Expression is not an integer\n";
		throw "Error";
	}
	if(cexpr != NULL){
		Array* arrayptr = dynamic_cast<Array*>($1->getExpressionType());
		if(arrayptr == NULL){
			std::cerr << "Somehow this got messed up!" << std::endl;
			std::cerr << $1->getExpressionType()->getTypeAsString() << std::endl;
			throw "error";
		}
		Write::comment("This is where the array is going to be found. The Expression is constant.");
		$$ = arrayptr->getExpressionAt(arraymem->getOffset(), arraymem->getPtrReference(), cexpr->getElement());
	} else {
		Array* arrayptr = dynamic_cast<Array*>($1->getExpressionType());
		if(arrayptr == NULL){
			std::cerr << "Cannot index this variable type!" << std::endl;
			std::cerr << $1->getExpressionType()->getTypeAsString() << std::endl;
			throw "error";
		}
		Write::comment("This is where the array is going to be found. The Expression is not constant.");
		RegExpression* r = $3->copyAsRegExpression();
		$$ = arrayptr->getExpressionAt(arraymem->getOffset(), arraymem->getPtrReference(), r);
	}
	MemExpression* m3 = dynamic_cast<MemExpression*>($3);
	if(m3 == NULL) {
		delete $3;
	}
	else if(m3->isTemporary()){
		delete $3;
	}
}; // And this one is for arrays


Expression: Expression OR Expression {
	$$ = $1->orfun($3);
	MemExpression* m1 = dynamic_cast<MemExpression*>($1);
	MemExpression* m3 = dynamic_cast<MemExpression*>($3);
	if(m1 == NULL) {
		delete $1;
	}
	else if(m1->isTemporary()){
		delete $1;
	}
	if(m3 == NULL) {
		delete $3;
	}
	else if(m3->isTemporary()){
		delete $3;
	}
}
| Expression AND Expression {
	$$ = $1->andfun($3);
	MemExpression* m1 = dynamic_cast<MemExpression*>($1);
	MemExpression* m3 = dynamic_cast<MemExpression*>($3);
	if(m1 == NULL) {
		delete $1;
	}
	else if(m1->isTemporary()){
		delete $1;
	}
	if(m3 == NULL) {
		delete $3;
	}
	else if(m3->isTemporary()){
		delete $3;
	}
}
| Expression EQ Expression {
	$$ = $1->eq($3);
	MemExpression* m1 = dynamic_cast<MemExpression*>($1);
	MemExpression* m3 = dynamic_cast<MemExpression*>($3);
	if(m1 == NULL) {
		delete $1;
	}
	else if(m1->isTemporary()){
		delete $1;
	}
	if(m3 == NULL) {
		delete $3;
	}
	else if(m3->isTemporary()){
		delete $3;
	}
}
| Expression ARROWS Expression {
	$$ = $1->ne($3);
	MemExpression* m1 = dynamic_cast<MemExpression*>($1);
	MemExpression* m3 = dynamic_cast<MemExpression*>($3);
	if(m1 == NULL) {
		delete $1;
	}
	else if(m1->isTemporary()){
		delete $1;
	}
	if(m3 == NULL) {
		delete $3;
	}
	else if(m3->isTemporary()){
		delete $3;
	}
}
| Expression GTE Expression {
	$$ = $1->gte($3);
	MemExpression* m1 = dynamic_cast<MemExpression*>($1);
	MemExpression* m3 = dynamic_cast<MemExpression*>($3);
	if(m1 == NULL) {
		delete $1;
	}
	else if(m1->isTemporary()){
		delete $1;
	}
	if(m3 == NULL) {
		delete $3;
	}
	else if(m3->isTemporary()){
		delete $3;
	}
}
| Expression GT Expression {
	$$ = $1->gt($3);
	MemExpression* m1 = dynamic_cast<MemExpression*>($1);
	MemExpression* m3 = dynamic_cast<MemExpression*>($3);
	if(m1 == NULL) {
		delete $1;
	}
	else if(m1->isTemporary()){
		delete $1;
	}
	if(m3 == NULL) {
		delete $3;
	}
	else if(m3->isTemporary()){
		delete $3;
	}
}
| Expression LTE Expression {
	$$ = $1->lte($3);
	MemExpression* m1 = dynamic_cast<MemExpression*>($1);
	MemExpression* m3 = dynamic_cast<MemExpression*>($3);
	if(m1 == NULL) {
		delete $1;
	}
	else if(m1->isTemporary()){
		delete $1;
	}
	if(m3 == NULL) {
		delete $3;
	}
	else if(m3->isTemporary()){
		delete $3;
	}
}
| Expression LT Expression {
	$$ = $1->lt($3);
	MemExpression* m1 = dynamic_cast<MemExpression*>($1);
	MemExpression* m3 = dynamic_cast<MemExpression*>($3);
	if(m1 == NULL) {
		delete $1;
	}
	else if(m1->isTemporary()){
		delete $1;
	}
	if(m3 == NULL) {
		delete $3;
	}
	else if(m3->isTemporary()){
		delete $3;
	}
}
| Expression ADD Expression {
	$$ = $1->add($3);
	MemExpression* m1 = dynamic_cast<MemExpression*>($1);
	MemExpression* m3 = dynamic_cast<MemExpression*>($3);
	ConstExpression* c1 = dynamic_cast<ConstExpression*>($1);
	ConstExpression* c3 = dynamic_cast<ConstExpression*>($$);
	if(m1 == NULL) {
		delete $1;
	}
	else if(m1->isTemporary()){
		delete $1;
	}
	if(m3 == NULL) {
		delete $3;
	}
	else if(m3->isTemporary()){
		delete $3;
	}
}
| Expression SUB Expression {
	$$ = $1->sub($3);
	MemExpression* m1 = dynamic_cast<MemExpression*>($1);
	MemExpression* m3 = dynamic_cast<MemExpression*>($3);
	if(m1 == NULL) {
		delete $1;
	}
	else if(m1->isTemporary()){
		delete $1;
	}
	if(m3 == NULL) {
		delete $3;
	}
	else if(m3->isTemporary()){
		delete $3;
	}
}
| Expression MULT Expression {
	$$ = $1->mult($3);
	MemExpression* m1 = dynamic_cast<MemExpression*>($1);
	MemExpression* m3 = dynamic_cast<MemExpression*>($3);
	if(m1 == NULL) {
		delete $1;
	}
	else if(m1->isTemporary()){
		delete $1;
	}
	if(m3 == NULL) {
		delete $3;
	}
	else if(m3->isTemporary()){
		delete $3;
	}
}
| Expression DIV Expression {
	$$ = $1->div($3);
	MemExpression* m1 = dynamic_cast<MemExpression*>($1);
	MemExpression* m3 = dynamic_cast<MemExpression*>($3);
	if(m1 == NULL) {
		delete $1;
	}
	else if(m1->isTemporary()){
		delete $1;
	}
	if(m3 == NULL) {
		delete $3;
	}
	else if(m3->isTemporary()){
		delete $3;
	}
}
| Expression PERC Expression {
	$$ = $1->mod($3);
	MemExpression* m1 = dynamic_cast<MemExpression*>($1);
	MemExpression* m3 = dynamic_cast<MemExpression*>($3);
	if(m1 == NULL) {
		delete $1;
	}
	else if(m1->isTemporary()){
		delete $1;
	}
	if(m3 == NULL) {
		delete $3;
	}
	else if(m3->isTemporary()){
		delete $3;
	}
}
| TILDA Expression {}
| SUB Expression {}
| POPEN Expression PCLOSE { 
	$$ = $2; 
}
| ID POPEN ExpressionsList PCLOSE {
//		std::cout << $1 << std::endl;
}
| ID POPEN PCLOSE {
	//std::cerr << $1 << std::endl;
}
| CHR POPEN Expression PCLOSE {
	$3->chr();
	$$ = $3;
	//std::cerr << "I htink that worked kind of\n";
}
| ORD POPEN Expression PCLOSE {
	$3->ord();
	$$ = $3;
}
| PRED POPEN Expression PCLOSE {
	ConstExpression* c = new ConstExpression(1);
	$$ = $3->sub(c);
	delete c;
	MemExpression* m3 = dynamic_cast<MemExpression*>($3);
	if(m3 == NULL){
		delete $3;
	}
	else if (m3->isTemporary()){
		delete $3;
	}
}
| SUCC POPEN Expression PCLOSE {
	ConstExpression* c = new ConstExpression(1);
	$$ = $3->add(c);
	delete c;
	MemExpression* m3 = dynamic_cast<MemExpression*>($3);
	if(m3 == NULL){
		delete $3;
	}
	else if (m3->isTemporary()){
		delete $3;
	}
}
| LValue {
	$$ = $1;
}
| STR {
	$$ = new ConstExpression(strlist->add(std::string($1)), new String());
}
| CHAR {
	int length = strlen($1);
	char c;
	if (length == 3){
		c = $1[1]; 
	}
	else if(length == 4){
		std::string s;
		s += $1[1]; 
		s += $1[2]; 
		std::string temp;
		temp += '\\';
		temp += 'n';
		if (! s.compare(temp)){
			c = '\n';
		}
		else{
			std::cerr << "Somehow a wrong whitespace character showed up!";
		}
	}
	$$ = new ConstExpression(int(c), new Char()); //TODO Make sure that this isn't spaghetti code. I think the index is 1 because the str looks like 'x'
}
| NUMBER {
	$$ = new ConstExpression($1); 
};

%%
void yyerror(const char* message){
	std::cerr << message  << " on line " << yylineno << std::endl;
}
